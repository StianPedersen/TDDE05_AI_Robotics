import torch
from transformers import BertTokenizer
import numpy as np
from transformers import AutoTokenizer, AutoModelForTokenClassification, pipeline
from subprocess import run

def preprocessing(input_text, tokenizer):
    return tokenizer.encode_plus(input_text,add_special_tokens = True,max_length = 32,pad_to_max_length = True,return_attention_mask = True,return_tensors = 'pt')


class TDDE05_model:
    def __init__(self):
        self.model_intent = model = torch.load("models/intent_model.pt")
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

#    category  label
# 25   Coffee      0
# 15  Explore      1
# 0      Goto      2
def main():
    robot_model = TDDE05_model()
    
    while True:
        print("Say something")
        s = str(input())
        what_to_do = robot_model.pass_both(s)
        print(what_to_do)
        print()

if __name__ == "__main__":
    main()