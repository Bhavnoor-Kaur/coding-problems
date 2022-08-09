def getSquares(arr):
    n = len(arr)
    squares = [0 for x in range(n)]
    highestIndex = n - 1
    left = 0
    right = len(arr) - 1
    while (left < right):
        leftSquare = arr[left] * arr[left]
        rightSquare = arr[right] * arr[right]

        if (leftSquare > rightSquare):
            squares[highestIndex] = leftSquare
            left += 1
        else:
            squares[highestIndex] = rightSquare
            right -= 1
        
        highestIndex -= 1

    return squares

def main():
    print(getSquares([-2, -1, 0, 2, 3]))
    print(getSquares([-3, -1, 0, 1, 2]))

main()
