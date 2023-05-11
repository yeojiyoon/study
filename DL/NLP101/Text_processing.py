import re #정규 표현식 라이브러리

text = "I was wondering if anyone out there could enlighten me on this car."

shortword = re.compile(r'\W*\b\w{1,2}\b') #정규식 객체 리턴
print(shortword.sub('', text))