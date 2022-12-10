# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def find_sum(self, node, preprocessing=False):
        if not node:
            return 0
        nsum = 0
        if node.left:
            nsum += self.find_sum(node.left)
        if node.right:
            nsum += self.find_sum(node.right)
        nsum += node.val
        if not preprocessing:
            product_sum = (nsum*(self.total_sum-nsum))
            if product_sum>self.max_product:
                self.max_product = product_sum
        return nsum

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.total_sum = 0
        self.max_product = -1
        self.total_sum = self.find_sum(root, True)
        self.total_sum = self.find_sum(root)
        return self.max_product%((10**9)+7)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
