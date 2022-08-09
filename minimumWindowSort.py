import math

def shortestWindowSort(arr):
    low = 0
    high = len(arr) - 1

    while(low < len(arr) - 1 and arr[low] <= arr[low + 1]):
        low += 1
    
    if low == len(arr) - 1:
        return 0
    
    while (high > 0 and arr[high] >= arr[high - 1]):
        high -= 1
    
    subarrayMax = -math.inf
    subarrayMin = math.inf

    for k in range(low, high + 1):
        subarrayMax = max(subarrayMax, arr[k])
        subarrayMin = min(subarrayMin, arr[k])

    while(low > 0 and arr[low-1] > subarrayMin):
        low -= 1
    
    while (high < len(arr) - 1 and arr[high + 1] < subarrayMax):
        high += 1
    
    return high - low + 1

def main():
    print(shortestWindowSort([1, 2, 5, 3, 7, 10, 9, 12]))
    print(shortestWindowSort([1, 3, 2, 0, -1, 7, 10]))
    print(shortestWindowSort([1, 2, 3]))
    print(shortestWindowSort([3, 2, 1]))

main()