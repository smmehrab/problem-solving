# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import Counter, defaultdict

class Solution:
    def _dfs(self, node, parent):
        count = Counter()
        for neighbor in self.tree[node]:
            if neighbor != parent:
                count += self._dfs(neighbor, node)
        count[self.labels[node]] += 1
        self.node_counts[node] = count[self.labels[node]]
        return count

    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        self.labels = labels
        self.tree = defaultdict(list)
        for u, v in edges:
            self.tree[u].append(v)
            self.tree[v].append(u)
        self.node_counts = [0] * n
        self._dfs(0, -1)
        return self.node_counts