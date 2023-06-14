# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def traverse(self, root, d, a):
        if root.left:
            d = self.traverse(root.left, d, a)

        a.append(root.val)
        if len(a)>1:
            d = min(d, a[-1]-a[-2])

        if root.right:
            d = self.traverse(root.right,d,a) 
        return d

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        return self.traverse(root, float('inf'), [])

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
