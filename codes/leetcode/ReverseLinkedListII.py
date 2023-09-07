# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right or head == None:
            return head
        node = head
        previous = None
        reverse_head = None
        reverse_tail = None
        reverse_left = None
        reverse_right = None
        index = 0
        while node:
            index += 1
            if index >= left and index <= right:
                if index == left:
                    reverse_right = node
                elif index == right:
                    reverse_left = node
                temp = node.next
                node.next = previous
                previous = node
                node = temp
            else:
                if index == left-1:
                    reverse_head = node
                elif index == right+1:
                    reverse_tail = node
                previous = node
                node = node.next

        if reverse_right:
            reverse_right.next = reverse_tail
        if reverse_head == None:
            return reverse_left

        reverse_head.next = reverse_left
        return head

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next