# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        if len(graph) == 0:
            return 0

        n = len(graph)
        goal_state = (1 << n) - 1
        queue = deque()
        for node in range(n):
            queue.append((node, 1 << node, 0))

        visited = set()
        while queue:
            node, state, distance = queue.popleft()
            if state == goal_state:
                return distance
            if (node, state) in visited:
                continue
            visited.add((node, state))
            for neighbor in graph[node]:
                queue.append((neighbor, state | (1 << neighbor), distance + 1))

        return -1