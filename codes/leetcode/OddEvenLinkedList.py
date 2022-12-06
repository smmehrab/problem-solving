# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ohead, ehead = ListNode(None), ListNode(None)
        onode, enode = ohead, ehead
        even_index = True
        while head != None:
            if even_index:
                onode.next = head
                onode = onode.next
            else:
                enode.next = head
                enode = enode.next
            even_index = not even_index
            head = head.next
        onode.next = ehead.next
        enode.next = None

        head = ohead
        head.next = ohead.next
        head = head.next
        return head

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
