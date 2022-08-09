def pairWithTargetSum(arr, targetSum):
    left = 0
    right = len(arr) - 1

    while (left < right):
        currentSum = arr[left] + arr[right]
        if (currentSum > targetSum):
            right = right - 1
        elif (currentSum < targetSum):
            left = left + 1
        elif (currentSum == targetSum):
            return [left, right]

    return [-1, -1]

def main():
    print(pairWithTargetSum([1, 2, 3, 4, 6], 6))
    print(pairWithTargetSum([2, 5, 9, 11], 11))

main()