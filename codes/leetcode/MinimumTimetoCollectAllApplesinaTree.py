# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, node, parent):
        time = 0
        for neighbor in self.graph[node]:
            if neighbor == parent:
                continue
            subtree_time = self._dfs(neighbor, node)
            if subtree_time or self.hasApple[neighbor]:
                time += subtree_time
                time += 2
        return time

    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        self.hasApple = hasApple
        self.graph = {node:[] for node in range(n)}
        for u, v in edges:
            self.graph[u].append(v)
            self.graph[v].append(u)
        return self._dfs(0, -1)