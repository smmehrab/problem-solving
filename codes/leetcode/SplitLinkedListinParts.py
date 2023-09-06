# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

import math

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        
        # Linked List Length
        node = head
        length = 0
        while node:
            length += 1
            node = node.next

        # Equally Distribute Part Sizes
        min_part_size = length//k
        remnant = length - (min_part_size*k)
        part_index = 0
        part_sizes = [min_part_size]*k
        while remnant > 0:
            part_sizes[part_index] += 1
            part_index += 1
            remnant -= 1

        # Split Linked List
        node = head
        index = 0
        part_index = 0
        parts = []
        while node:
            index+= 1
            if index == 1:
                parts.append(node)
            if index == part_sizes[part_index]:
                tmp = node.next
                node.next = None
                node = tmp
                index = 0
                part_index += 1
                continue
            node = node.next
    
        while part_index < k:
            parts.append(node)
            part_index += 1

        return parts

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next