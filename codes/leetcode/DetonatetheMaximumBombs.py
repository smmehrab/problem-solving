# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict, deque

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)
    
    def add(self, parent, child):
        self.graph[parent].append(child)

    def bfs(self, source):
        visited = []
        queue = deque()

        current_level = 0
        queue.append((source, 0))
        visited.append(source)
        while queue:
            node, level = queue.popleft()
            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    visited.append(neighbor)
                    queue.append((neighbor, level+1))

        return len(visited)


class Solution(object):
    def maximumDetonation(self, bombs):
        """
        :type bombs: List[List[int]]
        :rtype: int
        """

        graph = Graph()
        for index1, bomb1 in enumerate(bombs):
            x1, y1, r1 = bomb1
            for index2, bomb2 in enumerate(bombs):
                if index1 != index2:
                    x2, y2, r2 = bomb2
                    c1c2 = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2))
                    if c1c2 <= (r1*r1):
                        graph.add(index1, index2)

        maximum_detonation = 0
        for index, bomb in enumerate(bombs):
            detonation = graph.bfs(index)
            maximum_detonation = max(maximum_detonation, detonation)

        return maximum_detonation
