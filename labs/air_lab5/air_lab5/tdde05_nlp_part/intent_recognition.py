import torch
from torch.utils.data import TensorDataset, DataLoader, RandomSampler, SequentialSampler
from transformers import BertTokenizer, BertForSequenceClassification
from sklearn.model_selection import train_test_split
from sklearn import preprocessing

import pandas as pd
import numpy as np

from tqdm import trange

colnames=['category', 'text'] 
df = pd.read_csv('data/data-main/train.csv', names = colnames, header=None)
le = preprocessing.LabelEncoder()
le.fit(df['category'])

df['label']= le.transform(df['category'])
df['text'] = df['text'].astype(str)
df.head()
out = df.drop_duplicates(subset = "category")
out = out.drop(df.columns[[ 1]], axis=1)
out = out.sort_values(by=['category'])

text = df.text.values
labels = df.label.values

tokenizer = BertTokenizer.from_pretrained('bert-base-uncased', do_lower_case = True)

token_id = []
attention_masks = []

def preprocessing(input_text, tokenizer):
  return tokenizer.encode_plus(input_text,add_special_tokens = True,max_length = 32,pad_to_max_length = True,return_attention_mask = True,return_tensors = 'pt')


for sample in text:
  encoding_dict = preprocessing(sample, tokenizer)
  token_id.append(encoding_dict['input_ids']) 
  attention_masks.append(encoding_dict['attention_mask'])


token_id = torch.cat(token_id, dim = 0)
attention_masks = torch.cat(attention_masks, dim = 0)
labels = torch.tensor(labels)

batch_size = 16

    

train_set = TensorDataset(token_id, 
                          attention_masks, 
                          labels)


train_dataloader = DataLoader(
            train_set,
            sampler = RandomSampler(train_set),
            batch_size = batch_size
        )



model = BertForSequenceClassification.from_pretrained(
    'bert-base-uncased',
    num_labels = 3,
    output_attentions = False,
    output_hidden_states = False,
)

optimizer = torch.optim.AdamW(model.parameters(), 
                              lr = 5e-5,
                              eps = 1e-08
                              )

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

epochs = 4

for _ in trange(epochs, desc = 'Epoch'):
    
    # ========== Training ==========
    
    # Set model to training mode
    model.train()
    
    # Tracking variables
    tr_loss = 0
    nb_tr_examples, nb_tr_steps = 0, 0

    for step, batch in enumerate(train_dataloader):
        batch = tuple(t.to(device) for t in batch)
        b_input_ids, b_input_mask, b_labels = batch
        optimizer.zero_grad()
        # Forward pass
        train_output = model(b_input_ids, 
                             token_type_ids = None, 
                             attention_mask = b_input_mask, 
                             labels = b_labels)
        # Backward pass
        train_output.loss.backward()
        optimizer.step()
        # Update tracking variables
        tr_loss += train_output.loss.item()
        nb_tr_examples += b_input_ids.size(0)
        nb_tr_steps += 1

print("The classes:", out)
print("Model saved to models/intent_model.pt ")
torch.save(model, "models/intent_model.pt")