def add(a, b):
    return a + b

def sub(a, b):
    return a - b

if __name__ == "__main__": #직접 해당 파일을 실행하는 경우에만 __name__=="main" 문장이 참이 되어 해당 블록이 수행
    print(add(1,4))
    print(sub(4,2))