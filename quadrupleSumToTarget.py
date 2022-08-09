def searchQuadruples(arr, target):
    arr.sort()
    quadruples = []

    for first in range(len(arr)-3):
        if first > 0 and arr[first] == arr[first- 1]:
            continue
        for second in range(first+1, len(arr) - 2):
            if second > first+1 and arr[second] == arr[second-1]:
                continue
            left = second+1
            right = len(arr) - 1
            while(left < right):
                sum = arr[first] + arr[second] + arr[left] +arr[right]
                if sum == target:
                    quadruples.append([arr[first], arr[second], arr[left], arr[right]])
                    left += 1
                    right -= 1
                    while(left < right and arr[left == arr[left - 1]]):
                        left += 1
                    while (left < right and arr[right == arr[right + 1]]):
                        right -= 1
                elif sum < target:
                    left += 1
                else:
                    right -= 1
    return quadruples

def main():
    print(searchQuadruples([4, 1, 2, -1, 1, -3], 1))
    print(searchQuadruples([2, 0, -1, 1, -2, 2], 2))

main()

