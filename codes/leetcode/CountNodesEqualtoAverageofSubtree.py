# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def traverse(self, node):
        if not node:
            return 0, 0

        left_sum, left_count = self.traverse(node.left)
        right_sum, right_count = self.traverse(node.right)

        current_sum = node.val + left_sum + right_sum
        current_count = 1 + left_count + right_count

        avg = current_sum // current_count
        if avg == node.val:
            self.result += 1

        return current_sum, current_count

    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        self.result = 0
        self.traverse(root)
        return self.result

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right