# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, node):
        self.dist[node] = 1
        for neighbor in self.tree[node]:
            self._dfs(neighbor)
            if self.s[neighbor] != self.s[node]:
                self.path_len = max(self.path_len, self.dist[node]+self.dist[neighbor])
                self.dist[node] = max(self.dist[node], 1+self.dist[neighbor])

    def longestPath(self, parent: List[int], s: str) -> int:
        self.n = len(s)
        self.s = s
        self.parent = parent
        self.tree = [[] for i in range(self.n)]
        self.dist = [0]*self.n
        self.path_len = 1

        for u, v in enumerate(self.parent):
            if v >= 0:
                self.tree[v].append(u)
        self._dfs(0)
        return self.path_len