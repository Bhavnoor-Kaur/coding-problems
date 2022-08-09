class Node:
    def __init__(self, value, next= None):
        self.value = value
        self.next = next

def isPalindrome(head):
    if head is None or head.next is None:
        return True

    slow, fast = head, head
    while(fast is not None and fast.next is not None):
        slow = slow.next
        fast = fast.next.next

    headSecondHalf = reverse(slow)

    copyHeadSecondHalf = headSecondHalf

    while(head is not None and headSecondHalf is not None):
        if head.value != headSecondHalf.value:
            break

        head = head.next
        headSecondHalf = headSecondHalf.next

    reverse(copyHeadSecondHalf)

    if head is None or headSecondHalf is None:
        return True

    return False

def reverse(head):
    prev = None
    while(head is not None):
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev

def main():
    head = Node(2)
    head.next = Node(4)
    head.next.next = Node(6)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(2)

    print("Is palindrome: " + str(isPalindrome(head)))

    head.next.next.next.next.next = Node(2)
    print("Is palindrome: " + str(isPalindrome(head)))

main()