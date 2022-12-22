# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict

"""
    distance_sum[i] = parent_sum - (1*closer_nodes) + (1*farther_nodes)
    farther_nodes = n - closer_nodes
"""

class Solution:

    def _dfs_node_count(self, node):
        node_count = 1
        self.visited.add(node)
        for neighbor in self.graph[node]:
            if neighbor not in self.visited:
                subtree_node_count = self._dfs_node_count(neighbor)
                node_count += subtree_node_count
                self.distance_sums[0] += subtree_node_count
        self.node_counts[node] = node_count
        return node_count

    def _dfs_distance_sum(self, node):
        self.visited.add(node)
        for neighbor in self.graph[node]:
            if neighbor not in self.visited:
                self.distance_sums[neighbor] = self.distance_sums[node]
                self.distance_sums[neighbor] -= self.node_counts[neighbor]
                self.distance_sums[neighbor] += (self.n - self.node_counts[neighbor])
                self._dfs_distance_sum(neighbor)

    def sumOfDistancesInTree(self, n: int, edges: list[list[int]]) -> list[int]:

        self.n = n
        self.graph = defaultdict(list)
        self.node_counts = [0]*n
        self.distance_sums = [0]*n

        for a, b in edges:
            self.graph[a].append(b)
            self.graph[b].append(a)

        self.visited = set()
        self._dfs_node_count(0)

        self.visited = set()
        self._dfs_distance_sum(0)

        return self.distance_sums