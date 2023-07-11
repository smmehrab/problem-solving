# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List

class Solution:

    def mark_parents(self, node, parent):
        if node is None:
            return 

        self.parents[node] = parent

        self.mark_parents(node.left, node)
        self.mark_parents(node.right, node)

    def find_k_distance_nodes(self, node, distance):
        if not node or node in self.visited or distance > self.k:
            return 

        self.visited.add(node)
        if distance == self.k:
            self.k_distance_nodes.append(node.val)

        self.find_k_distance_nodes(node.left, distance + 1)
        self.find_k_distance_nodes(node.right, distance + 1)
        self.find_k_distance_nodes(self.parents[node], distance + 1)

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:

        self.parents = {}
        self.mark_parents(root, None)

        self.k = k
        self.visited = set()
        self.k_distance_nodes = []
        self.find_k_distance_nodes(target, 0)
        return self.k_distance_nodes

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
