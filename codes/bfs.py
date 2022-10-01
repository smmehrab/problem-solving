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

            # output
            if level>current_level:
                print("")
                current_level = level
            print(node, end = " ")

            for neighbor in self.graph[node]:
                if neighbor not in visited:
                    visited.append(neighbor)
                    queue.append((neighbor, level+1))
        # output
        print("")
