# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
       
        node = head
        for _ in range(k-1):
            node = node.next
        left = node

        right = head
        while node.next:
            node = node.next
            right = right.next

        left.val, right.val = right.val, left.val
        return head