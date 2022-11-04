# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # two pointers initial
        left = head
        right = head
        for i in range(n):
            right = right.next

        # find
        previous = None
        while right:
            previous = left
            left = left.next
            right = right.next

        # delete
        if previous:
            previous.next = left.next
        else:
            head = left.next

        return head
