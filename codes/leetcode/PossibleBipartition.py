# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict, deque

class Solution:
    def _bfs(self, source):
        queue = deque()
        self.color[source] = 0
        queue.append(source)
        while queue:
            node = queue.popleft()
            for neighbor in self.graph[node]:
                if self.color[neighbor] == self.color[node]:
                    return False
                if self.color[neighbor] == -1:
                    self.color[neighbor] = 1-self.color[node]
                    queue.append(neighbor)
        return True

    def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:

        self.graph = defaultdict(list)
        self.color = [-1]*n

        for a, b in dislikes:
            self.graph[a-1].append(b-1)
            self.graph[b-1].append(a-1)

        is_bipartite = True
        for i in range(n):
            if self.color[i] == -1:
                is_bipartite = self._bfs(i)
                if not is_bipartite:
                    return is_bipartite
        return is_bipartite
