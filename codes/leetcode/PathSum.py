# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):

    def traverse(self, node, sum):
        has_path = False
        if (not node.left and not node.right):
            has_path = (sum==node.val)
        if node.left:
            has_path |= self.traverse(node.left, (sum-node.val))
        if node.right:
            has_path |= self.traverse(node.right, (sum-node.val))
        return has_path

    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if not root:
            return False
        return self.traverse(root, targetSum)
