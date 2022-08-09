def tripletsWithSmallerSum(arr, target):
    count = 0
    arr.sort()

    for i in range(len(arr)-2):
        left = i+1
        right = len(arr) - 1

        while (left < right):
            currentSum = arr[left] + arr[right] + arr[i]
            if currentSum < target:
                count += right - left
                left += 1
            else:
                right -= 1
            
    return count


def main():
    print(tripletsWithSmallerSum([-1, 0, 2, 3], 3))
    print(tripletsWithSmallerSum([-1, 4, 2, 1, 3], 5))

main()