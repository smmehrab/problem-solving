# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Graph:
    def __init__(self, n):
        self.n = n
        self.graph = {node: [] for node in range(self.n)}

    # DFS
    def _helper(self, source, visited, result):
        stack = [(source, self.graph[source])]
        while stack:
            node, neighbors = stack.pop()
            visited[node] = True
            for neighbor in neighbors:
                if not visited[neighbor]:
                    stack.append((node, neighbors))
                    stack.append((neighbor, self.graph[neighbor]))
                    break
            else:
                result.append(node)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Topological Sort
    def topological_sort(self):
        visited = [False]*self.n

        result = []
        for node in range(self.n):
            if not visited[node]:
                self._helper(node, visited, result)
        result.reverse()
        return result

if __name__ == "__main__":
    graph = Graph(6)
    graph.add_edge(5, 2)
    graph.add_edge(5, 0)
    graph.add_edge(4, 0)
    graph.add_edge(4, 1)
    graph.add_edge(2, 3)
    graph.add_edge(3, 1)

    result = graph.topological_sort()

    print("Topologically Sorted:")
    print(result)

