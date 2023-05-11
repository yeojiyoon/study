# 주어진 문자열이 회문이면 True, 회문이 아니면 False를 반환하라.

def check_palindrome(text):
    half_len = len(text)
    flag = True
    iter = 1

    for alph in text:
        if alph == text[half_len-iter]:
            pass
        else:
            flag = False
        iter = iter + 1

    return flag


print(check_palindrome("madam")) #true
print(check_palindrome("tomato")) #false