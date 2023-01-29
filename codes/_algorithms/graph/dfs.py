# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)

    def add(self, parent, child):
        self.graph[parent].append(child)

    def dfs(self, node, visited = None):
        if visited is None:
            visited = []
        visited.append(node)
        print(node, end = " ")
        for neighbor in self.graph[node]:
            if neighbor not in visited:
                self.dfs(neighbor, visited)
        return visited

