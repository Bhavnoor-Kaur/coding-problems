from __future__ import print_function

class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def printList(self):
    temp = self
    while temp is not None:
        print(temp.value, end = '')
        temp = temp.next
    print()

def findCycleStart(head):
    cycleLength = 0

    slow, fast = head, head
    while(fast is not None and  fast.next is not None):
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            cycleLength = findCycleLength(slow)
            break
    return findStart(head, cycleLength)

def findCycleLength(slow):
    current = slow
    cycleLength = 0
    while True:
        current = current.next
        cycleLength += 1
        if current == slow:
            break
    return cycleLength

def findStart(head, cycleLength):
    pointer1 = head
    pointer2 = head

    while cycleLength > 0:
        pointer2 = pointer2.next
        cycleLength -= 1

    while pointer1 != pointer2:
        pointer1 = pointer1.next
        pointer2 = pointer2.next
    return pointer1


def main():
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head.next.next.next.next.next = Node(6)

    head.next.next.next.next.next.next = head.next.next
    print("LinkedList cycle start: " + str(findCycleStart(head).value))

    head.next.next.next.next.next.next = head.next.next.next
    print("LinkedList cycle start: " + str(findCycleStart(head).value))

    head.next.next.next.next.next.next = head
    print("LinkedList cycle start: " + str(findCycleStart(head).value))

main()