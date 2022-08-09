from email.errors import NonPrintableDefect
from multiprocessing.sharedctypes import Value


class Node:
    def __init__(self, value, next = None):
        self.value = value
        self.next = next

    def printList(self):
        temp = self
        while temp is not None:
            print(str(temp.value) + " ", end= '')
            temp = temp.next
        print()

def reorder(head):
    if head is None or head.next is None:
        return

    slow, fast = head, head
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

    headSecondHalf = reverse(slow)
    headFirstHalf = head

    while headFirstHalf is not None and headSecondHalf is not None:
        temp = headFirstHalf.next
        headFirstHalf.next = headSecondHalf
        headFirstHalf = temp

        temp = headSecondHalf.next
        headSecondHalf.next = headFirstHalf
        headSecondHalf = temp

    if headFirstHalf is not None:
        headFirstHalf.next = None

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
    head.next.next.next = Node(8)
    head.next.next.next.next = Node(10)
    head.next.next.next.next.next = Node(12)
    reorder(head)
    head.printList()

main()