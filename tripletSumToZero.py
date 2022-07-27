def searchTriplets(arr):
    arr.sort()
    triplets = []

    for i in range(len(arr)):
        left = i+1
        right = len(arr) - 1
        while (left < right):
            if (arr[left] + arr[right] + arr[i] == 0):
                triplets.append([arr[left], arr[right], arr[i]])
                left += 1
                right -= 1
            elif (arr[left] + arr[right] + arr[i] > 0):
                right -= 1
            else:
                left += 1

    return triplets

def main():
    print(searchTriplets([-3, 0, 1, 2, -1, 1, -2]))
    print(searchTriplets([-5, 2, -1, -2, 3]))

main()