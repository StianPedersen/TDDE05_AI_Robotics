from transformers import AutoTokenizer, AutoModelForTokenClassification, pipeline

bert_tokenizer = AutoTokenizer.from_pretrained('dslim/bert-large-NER')
bert_model = AutoModelForTokenClassification.from_pretrained('dslim/bert-large-NER')

nlp = pipeline('ner', model=bert_model, tokenizer=bert_tokenizer)
names_string = "Where can i find a man called David?"
ner_list = nlp(names_string)
print(ner_list)