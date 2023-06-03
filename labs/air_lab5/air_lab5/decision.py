import threading
import math

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
from air_lab_interfaces.msg import GoalsRequest
import json
from ros2_kdb_msgs.srv import QueryDatabase
from rclpy.callback_groups import ReentrantCallbackGroup
from air_lab_interfaces.srv import ExecuteTst


ros_name_counter = 0
def gen_name(name):
    global ros_name_counter
    ros_name_counter += 1
    return name + str(ros_name_counter)


class Client(Node):
    def __init__(self):
        super().__init__('cli')
        self.group = ReentrantCallbackGroup()

        self.cli = self.create_client(ExecuteTst, '/execute_tst', callback_group=self.group)

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = ExecuteTst.Request()

    def send_request(self,filename):
        print(type(filename))
        self.req.tst_file = filename

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class GetNodes(Node):
    def __init__(self):
        super().__init__('getnodes')
        self.group = ReentrantCallbackGroup()

        self.cli = self.create_client(QueryDatabase, '/kdb_server/sparql_query', callback_group=self.group)

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = QueryDatabase.Request()


    def send_request(self,attribute):
        self.req.graphname = "semanticobject"
        self.req.format = "json"
        self.req.query = f"""PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
                            PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>

                            SELECT ?obj_id ?class ?x ?y WHERE {{ ?obj_id a ?class;
                            properties:location [ gis:x ?x; gis:y ?y ];
                            properties:tags <{attribute}> . }}"""
  
        self.req.bindings = ""

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


class DecisionNode(Node):
  def create_goto_tst(self,goal_dest):
        client_node = GetNodes()
        tst_file_node = Client()
        print("goal",goal_dest)
        query_result = client_node.send_request(goal_dest)
        whole = {"children":[],"common_params":{},"name":"seq","params":{"repeat-count": 1}}
        json_result = json.loads(query_result.result)
        print(json_result)
        for row in json_result["results"]["bindings"]:
          if str(row['class']['value']) == "office":
              whole['children'].append({'children':[],
              'common_params':{},
              'name':'drive-to',
              'params':{'p':{"rostype":"Point","x":float(row['x']['value']),"y":float(row['y']['value']),"z":0,}}
              })

        y = json.dumps(whole,indent = 2)
        with open("src/labs/drive_to_human_lab5.json", "w") as outfile:
            outfile.write(y)
            print("file_written")
        tst_file_node.send_request("src/labs/drive_to_human_lab5.json")
           

        

  def create_bring_tst(self,goal_object, goal_dest):
        client_node = GetNodes()
        query_result = client_node.send_request(goal_object.lower())
        json_result = json.loads(query_result.result)
        tst_file_node = Client()
        # Find coordinates for robot now
        current_x = self.x
        current_y = self.y

        whole = {"children":[],"common_params":{},"name":"seq","params":{"repeat-count": 1}}
        print(json_result)
        # find coordinates for vending machine
        
        for row in json_result["results"]["bindings"]:
          if str(row['class']['value']) == "vendingmachine":
              whole['children'].append({'children':[],
              'common_params':{},
              'name':'drive-to',
              'params':{'p':{"rostype":"Point","x":float(row['x']['value']),"y":float(row['y']['value']),"z":0,}}
              })
              break


        whole['children'].append({'children':[],
            'common_params':{},
            'name':'drive-to',
            'params':{'p':{"rostype":"Point","x":float(current_x),"y":float(current_y),"z":0,}}
            })      

        y = json.dumps(whole,indent = 2)
        with open("src/labs/drive_to_vending.json", "w") as outfile:
            outfile.write(y)
            print("file_written")
        tst_file_node.send_request("src/labs/drive_to_vending.json")
        

  def create_explore_tst(self):
      tst_file_node = Client()
      whole = {"children":[],"common_params":{},"name":"seq","params":{}}
      whole['children'].append({'children':[],
            'common_params':{},
            'name':'explore',
            'params':{'radius':5, "a":0,"b":1}
            })       
      y = json.dumps(whole,indent = 2)
      with open("src/labs/explore_lab5.json", "w") as outfile:
          outfile.write(y)
          print("file_written")
      tst_file_node.send_request("src/labs/explore_lab5.json")
      

  def odom_listener_callback(self, msg):   
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y

  def listener_callback(self, goal_list):
    for goal in goal_list.goals:
      print(goal)
      if goal.type == "goto":
        print("in goto")
        self.create_goto_tst(goal.destination)
      elif goal.type == "bring":
        print("in bring")
        self.create_bring_tst(goal.object, goal.destination)
      elif goal.type == "explore":
        print("in explore")
        self.create_explore_tst()

  def __init__(self):
    print("Init lab5")
    super().__init__('decisionnode_lab5')
    self.x, self.y = 0,0

    self.subscription = self.create_subscription(GoalsRequest,'/goals_requests',self.listener_callback, 10)
    self.subscription
    self.odom_subscription = self.create_subscription(Odometry,'/odom',self.odom_listener_callback, 10) 
    self.odom_subscription  # prevent unused variable warning


  def finalise(self):
    self.executor.shutdown()


def main():
  print("Lab5")
  rclpy.init()
  node = DecisionNode()

  rclpy.spin(node)

if __name__ == '__main__':
    main()
