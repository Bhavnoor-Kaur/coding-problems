from collections import deque


def findSubarrays(arr, target):
    result = []
    product = 1

    left = 0
    for right in range(len(arr)):
        product *= arr[right]
        while (product >= target and left < len(arr)):
            product /= arr[left]
            left += 1
        tempList = deque()
        for i in range(right, left-1, -1):
            tempList.appendleft(arr[i])
            result.append(list(tempList))
    
    return result

def main():
    print(findSubarrays([2, 5, 3, 10], 30))
    print(findSubarrays([8, 2, 6, 5], 50))

main()