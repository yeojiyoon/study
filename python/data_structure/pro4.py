#정렬되지 않은 음이 아닌 정수로 이루어진 배열 A가 있다. 연속된 원소를 더한 값이 제시된 값 S와 같은 부분 배열을 찾아라. (인덱스 기준은 1이다.)

def subarray_with_sum(arr, sum):
    for i in range(len(arr)):
        subsum = arr[i]
        subarray = [i + 1]
        if subsum < sum:
            for j in range(i+1, len(arr)):
                subsum = subsum + arr[j]
                if subsum == sum:
                    subarray = subarray + [j + 1]
                    return subarray
                
print(subarray_with_sum([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 15))