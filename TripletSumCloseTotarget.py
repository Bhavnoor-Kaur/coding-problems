def TripleSumCloseToTarget(arr, target):
    arr.sort()
    diff = float('inf')
    closestSum = 0
    for i in range(len(arr)):
        left = i+1
        right = len(arr) - 1

        while(left < right):
            currentClosestSum = arr[left] + arr[right] + arr[i]
            currentDiff = target - currentClosestSum
            if abs(currentDiff) < abs(diff):
                diff = currentDiff 
                closestSum = currentClosestSum
            elif abs(currentDiff) == abs(diff):
                closestSum = min(closestSum, currentClosestSum)

            if ( closestSum > target):
                right -= 1
            else:
                left += 1
    return closestSum

def main():
    print(TripleSumCloseToTarget([-2, 0, 1, 2], 2))
    print(TripleSumCloseToTarget([-3, -1, 1, 2], 1))
    print(TripleSumCloseToTarget([1, 0, 1, 1], 100))

main()