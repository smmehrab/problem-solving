# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):

    def addOneRow(self, root, val, depth):
        """
        :type root: TreeNode
        :type val: int
        :type depth: int
        :rtype: TreeNode
        """

        if depth == 1:
            root = TreeNode(val, root, None)

        else:
            queue = deque()
            queue.append(root)
            current_depth = 1
            while queue and current_depth<depth-1:
                current_depth_nodes_count = len(queue)
                while current_depth_nodes_count:
                    current_depth_nodes_count -= 1
                    node = queue.popleft()
                    if node.left:
                        queue.append(node.left)
                    if node.right:
                        queue.append(node.right)
                current_depth += 1

            while queue:
                node = queue.popleft()
                node.left = TreeNode(val, node.left, None)
                node.right = TreeNode(val, None, node.right)

        return root