def dutchFlagSort(arr):
    left = 0
    right = len(arr) - 1

    i = 0
    while (i <= right):
        if (arr[i]) == 0:
            arr[i], arr[left] = arr[left], arr[i]
            i += 1
            left += 1
        elif (arr[i] == 2):
            arr[i], arr[right] = arr[right], arr[i]
            right -= 1
        else:
            i += 1
    
    return arr

def main():
    print(dutchFlagSort([1, 0, 2, 1, 0]))
    print(dutchFlagSort([2, 2, 0, 1, 2, 0]))

main()


        

