
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import rclpy.executors


import TstML
import TstML.Executor
from nav2_msgs.action import NavigateToPose
from nav2_msgs.msg import SpeedLimit 
import ament_index_python
from nav_msgs.msg import Odometry

from std_msgs.msg import String
from air_lab_interfaces.msg import Goal
from air_lab_interfaces.msg import GoalsRequest


from rclpy.callback_groups import ReentrantCallbackGroup

import torch
from transformers import BertTokenizer
import numpy as np
from transformers import AutoTokenizer, AutoModelForTokenClassification, pipeline
from subprocess import run

def preprocessing(input_text, tokenizer):
    return tokenizer.encode_plus(input_text,add_special_tokens = True,max_length = 32,pad_to_max_length = True,return_attention_mask = True,return_tensors = 'pt')


class TDDE05_model:
    def __init__(self):
        self.model_intent = torch.load("tdde05_nlp_part/models/intent_model.pt")
        self.tokenizer = BertTokenizer.from_pretrained('bert-base-uncased', do_lower_case = True)
        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        
        # Name finder
        self.bert_tokenizer = AutoTokenizer.from_pretrained('dslim/bert-large-NER')
        self.name_finder = AutoModelForTokenClassification.from_pretrained('dslim/bert-large-NER')
        self.nlp =pipeline('ner', model=self.name_finder, tokenizer=self.bert_tokenizer)
    def pass_sentence_intent(self,sentence):
        test_ids = []
        test_attention_mask = []
        encoding = preprocessing(sentence, self.tokenizer)
        test_ids.append(encoding['input_ids'])
        test_attention_mask.append(encoding['attention_mask'])
        test_ids = torch.cat(test_ids, dim = 0)
        test_attention_mask = torch.cat(test_attention_mask, dim = 0)
        with torch.no_grad():
          output = self.model_intent(test_ids.to(self.device), token_type_ids = None, attention_mask = test_attention_mask.to(self.device))
        prediction = np.argmax(output.logits.cpu().numpy()).flatten().item()
        return int(prediction)
    def pass_name_finder(self,sentence):
        name_dict = self.nlp(sentence)
        print(name_dict)
        if name_dict:
            result = name_dict[0]
            return str(result['word'])
        return None
    def pass_both(self,sentence):
        intent = self.pass_sentence_intent(sentence)
        if intent == 0:
            intent = "Bring Coffee"
        elif intent == 1:
            intent = "Explore"
        else:
            intent = "Goto"
        name = self.pass_name_finder(sentence)
        if name is not None:
            return intent + " " + name
        else:
            return intent 

ros_name_counter = 0
def gen_name(name):
    global ros_name_counter
    ros_name_counter += 1
    return name + str(ros_name_counter)

class TextNode(Node):
  def listener_callback(self, msg):    
    goal = Goal()
    msg = msg.data
    print("Original: ",msg)
    msg = self.nlp.pass_both(msg)
    print("Cmd: ",msg)

    if "Goto" in msg:
      goal.type = "goto"
      goal.object= ""
      goal.destination = msg.split(" ")[1]
    elif "Bring" in msg:
      goal.type = "bring"
      goal.object= msg.split(" ")[1]
      if msg.split(" ")[1] is not None:
        goal.destination = msg.split(" ")[2] # Need to test this
      else:
        goal.destination = None
    elif "Explore" in msg:
      goal.type = "explore"
      goal.object = ""
      goal.destination = ""

    goal_list = GoalsRequest()
    print(goal.type)
    goal_list.goals.append(goal)
    self.publisher_.publish(goal_list) # Send a list

  def __init__(self):
    print("Init lab5")
    super().__init__('textnode_lab5')
    self.nlp = TDDE05_model()
    # print("1")
    # self.executor = rclpy.executors.MultiThreadedExecutor()
    # print("1")
    
    # self.ros_node = Node(gen_name("text"))
    # self.publisher_ = self.ros_node.create_publisher(GoalsRequest, '/goals_requests', 1)

    # self.subscription = self.ros_node.create_subscription(String,'/text_command',self.listener_callback, 10)
    # self.subscription 

    self.publisher_ = self.create_publisher(GoalsRequest, '/goals_requests', 1)

    self.subscription = self.create_subscription(String,'/text_command',self.listener_callback, 10)
    self.subscription 

    # self.executor.add_node(self.ros_node)


    # self.thread = threading.Thread(target=self.executor.spin)
    # self.thread.start()

  def finalise(self):
    self.executor.shutdown()


def main():
  print("Lab5")
  rclpy.init()
  node = TextNode()
  rclpy.spin(node)

if __name__ == '__main__':
    main()
