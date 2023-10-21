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
    def _helper(self, source, visited, topological_order):
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
                topological_order.append(node)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Topological Sort with Kahn's Algorithm
    def topological_sort_kahn(self):

        in_degrees = [0]*(self.n)
        topological_order = []
        queue = []

        for node in self.graph:
            for neighbor in self.graph[node]:
                in_degrees[neighbor] += 1
 
        for i in range(self.n):
            if in_degrees[i] == 0:
                queue.append(i)
 
        while queue:
            node = queue.pop(0)
            topological_order.append(node)
            for neighbor in self.graph[node]:
                in_degrees[neighbor] -= 1
                if in_degrees[neighbor] == 0:
                    queue.append(neighbor)

        if len(topological_order) != self.n:
            print ("[Invalid Graph] No Topological Sort")
            return None

        return topological_order

    # Topological Sort with DFS
    def topological_sort_dfs(self):
        visited = [False]*self.n
        topological_order = []
        for node in range(self.n):
            if not visited[node]:
                self._helper(node, visited, topological_order)
        topological_order.reverse()
        return topological_order

if __name__ == "__main__":
    graph = Graph(6)
    graph.add_edge(5, 2)
    graph.add_edge(5, 0)
    graph.add_edge(4, 0)
    graph.add_edge(4, 1)
    graph.add_edge(2, 3)
    graph.add_edge(3, 1)

    topological_order1 = graph.topological_sort_dfs()
    topological_order2 = graph.topological_sort_kahn()

    print("Topological Order:")
    print(topological_order1)
    print(topological_order2)

