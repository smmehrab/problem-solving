# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict

class Solution:

    def _union(self, x, y):
        root_x = self._find(x)
        root_y = self._find(y)
        # smallest = root
        if root_x > root_y:
            self.disjoint_set[root_x] = root_y
        else:
            self.disjoint_set[root_y] = root_x

    def _find(self, x):
        self.disjoint_set.setdefault(x, x)
        if x != self.disjoint_set[x]:
            self.disjoint_set[x] = self._find(self.disjoint_set[x])
        return self.disjoint_set[x]

    def numberOfGoodPaths(self, values: List[int], edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        value_to_node = collections.defaultdict(list)
        for node, value in enumerate(values):
            value_to_node[value].append(node)

        good_paths = 0
        self.disjoint_set = {}

        for value in sorted(value_to_node.keys()):
            for node in value_to_node[value]:
                for neighbor in graph[node]:
                    if values[neighbor] <= values[node]:
                        self._union(neighbor, node)

            count = collections.defaultdict(int)
            for node in value_to_node[value]:
                root = self._find(node)
                count[root] += 1
                good_paths += count[root]

        return good_paths
