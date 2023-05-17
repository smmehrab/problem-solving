# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:

        head_previous = ListNode(0, head) 
        previous = head_previous
        current = head

        while current and current.next:
            next_pair = current.next.next
            second = current.next
            second.next = current
            current.next = next_pair
            previous.next = second
            previous = current
            current = next_pair

        return head_previous.next
