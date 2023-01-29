# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict, deque

class Graph:

    def __init__(self, n):
        self.n = n
        self.graph = defaultdict(list)
        self.color = [-1]*self.n

    def add(self, parent, child):
        self.graph[parent].append(child)
        self.graph[child].append(parent)

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

    def is_bipartite(self):
        self.color = [-1]*self.n
        is_bipartite = True
        for i in range(self.n):
            if self.color[i] == -1:
                is_bipartite = self._bfs(i)
                if not is_bipartite:
                    return is_bipartite
        return is_bipartite
