#정수로 이루어진 배열이 매개 변수로 주어질 때, 가장 큰 두 수를 찾아 (가장 큰 값, 둘째로 큰 값)을 반환하는 함수를 완성하라.

def find_two_max(input):
    if len(input) < 2:
        return input
    
    max1 = input[0]
    max2 = input[1]

    for num in input:
        if num > max1:
            max2 = max1
            max1 = num
        elif num > max2:
            max2 = num
    
    return [max1, max2]

print(find_two_max([3, -1, 5, 0, 7, 4, 9, 1]))