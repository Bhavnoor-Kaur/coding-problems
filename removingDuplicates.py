def removeDuplicates(arr):
    left = 1

    right = 1
    while(right < len(arr)):
        if arr[left - 1] != arr[right]:
            arr[left] = arr[right]
            left += 1
        right += 1

    return left
        
def main():
    print(removeDuplicates([2,3,3,3,6,9,9]))
    print(removeDuplicates([2,2,2,11]))

main()