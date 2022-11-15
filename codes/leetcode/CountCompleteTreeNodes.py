# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def find_tree_height(self, root):
        if root.left:
            return (1+self.find_tree_height(root.left))
        return 0

    def is_complete(self, root, h):
        if root:
            return self.is_complete(root.right, h-1)
        return (h==-1)

    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        h = self.find_tree_height(root)
        max_nodes = 1
        max_leaf_nodes = 1
        for i in range(h):
            max_leaf_nodes *= 2
            max_nodes += max_leaf_nodes
        
        half_of_max_leaf_nodes = max_leaf_nodes/2
        current = root
        while h>0:
            h -= 1
            if self.is_complete(current.left, h):
                current = current.right
            else:
                max_nodes -= half_of_max_leaf_nodes
                current = current.left
            half_of_max_leaf_nodes /= 2

        if not current:
            max_nodes -= 1

        return int(max_nodes)
