# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def traverse(self, node, leafs):
        if node.left:
            self.traverse(node.left, leafs)
        if not node.left and not node.right:
            leafs.append(node.val)
        if node.right:
            self.traverse(node.right, leafs)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaf_sequence1, leaf_sequence2 = [], []
        self.traverse(root1, leaf_sequence1)
        self.traverse(root2, leaf_sequence2)
        return leaf_sequence1 == leaf_sequence2

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
