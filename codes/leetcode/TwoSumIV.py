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
    def search(self, root, k, visited):
        
        if not root:
            return False
        
        if self.search(root.left, k, visited):
            return True
        
        if (k-root.val) in visited:
            return True
        else:
            visited.append(root.val)
        
        return self.search(root.right, k, visited)
    
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        return self.search(root, k, [])
