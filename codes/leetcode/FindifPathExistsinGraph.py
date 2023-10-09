# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict, deque

class Solution:

    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        if n<2 or source == destination:
            return True

        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # BFS
        visited = []
        queue = deque()
        queue.append(source)
        visited.append(source)
        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.append(neighbor)
                    queue.append(neighbor)
                    if neighbor == destination:
                        return True
        return False