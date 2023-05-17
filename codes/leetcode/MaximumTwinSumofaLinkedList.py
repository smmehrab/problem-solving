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
    def pairSum(self, head: Optional[ListNode]) -> int:

        node = head
        n = 0
        stack = []
        while node:
            stack.append(node.val)
            node = node.next
            n += 1
    
        node = head
        i = 0
        limit = n/2
        max_twin_sum = -1
        while i<limit:
            twin = stack.pop()
            twin_sum = twin + node.val
            max_twin_sum = max(max_twin_sum, twin_sum)
            node = node.next
            i += 1

        return max_twin_sum