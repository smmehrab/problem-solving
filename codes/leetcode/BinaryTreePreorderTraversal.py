# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        traversal = []
        stack = []
        stack.append(root)
        while stack:
            node = stack.pop()
            if not node:
                continue
            traversal.append(node.val)
            stack.append(node.right)
            stack.append(node.left)
        return traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right