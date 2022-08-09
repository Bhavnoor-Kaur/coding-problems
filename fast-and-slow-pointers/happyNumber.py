def findHappyNum(num):
    slow = num
    fast = num
    while True:
        slow = findSquareSum(slow)
        fast = findSquareSum(findSquareSum(fast))

        if slow == fast:
            break

    return slow == 1

def findSquareSum(num):
    sum = 0
    while(num > 0):
        digit = num % 10
        sum += digit * digit
        num //= 10
    return sum

def main():
    print(findHappyNum(23))
    print(findHappyNum(12))

main()