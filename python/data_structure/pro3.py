# 0과 1로만 이루어진 배열이 있다. 배열 자체를 오름차순으로 정렬하라.

def bubble_sort(arr):
    for i in range(len(arr) - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

arr = [1,0,1,1,0,0,0,1]

bubble_sort(arr)
print(arr)