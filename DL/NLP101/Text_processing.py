import re #정규 표현식 라이브러리
import nltk
from nltk.stem import WordNetLemmatizer
from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize

#nltk.download('wordnet')
#nltk.download('punkt')

###----정규화----###

text = "I was wondering if anyone out there could enlighten me on this car."

shortword = re.compile(r'\W*\b\w{1,2}\b') #정규식 객체 리턴
print(shortword.sub('', text))

###----표제어 추출----###

lemmatizer = WordNetLemmatizer() #nltk의 표제어 추출 도구

words = ['policy', 'doing', 'organization', 'have', 'going', 'love', 'lives', 'fly', 'dies', 'watched', 'has', 'starting']

print('표제어 추출 전 :',words)
print('표제어 추출 후 :', [lemmatizer.lemmatize(word) for word in words])

####---어간 추출---###

stemmer = PorterStemmer() #어간 추출 알고리즘 중 하나인 포터 알고리즘

sentence = "This was not the map we found in Billy Bones's chest, but an accurate copy, complete in all things--names and heights and soundings--with the single exception of the red crosses and the written notes."

tokenized_sentence = word_tokenize(sentence)

print('어간 추출 전 :', tokenized_sentence)
print('어간 추출 후 : ', [stemmer.stem(word) for word in tokenized_sentence])