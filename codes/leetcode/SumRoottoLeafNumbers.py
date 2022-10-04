# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):

    def traverse(self, node, path_sum):
        if not node:
            return 0
        
        path_sum = (path_sum*10) + node.val
        
        if not node.left and not node.right:
            return path_sum
        return self.traverse(node.left, path_sum) + self.traverse(node.right, path_sum)

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.traverse(root, 0)
