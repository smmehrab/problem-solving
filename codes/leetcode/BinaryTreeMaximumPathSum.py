# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, node):
        if not node:
            return 0
        left_max_without_splitting = max(0, self._dfs(node.left))
        right_max_without_splitting = max(0, self._dfs(node.right))

        max_with_splitting = left_max_without_splitting + node.val + right_max_without_splitting
        max_without_splitting = node.val + max(left_max_without_splitting, right_max_without_splitting)

        if self.answer < max_with_splitting:
            self.answer = max_with_splitting

        return max_without_splitting

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.answer = float('-inf')
        self._dfs(root)
        return self.answer

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right