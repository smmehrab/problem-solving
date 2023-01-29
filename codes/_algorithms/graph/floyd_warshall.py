# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Graph:

    """
        Floyd Warshall Algorithm
        O(V^3)
    """

    def __init__(self, number_of_vertices):
        self.graph = []
        self.V = number_of_vertices

    def add(self, u, v, w):
        self.graph.append([u, v, w])

    def _output(self, distances):
        print("{0}\t\t{1}".format("Vertex", "Distance"))
        for i in range(self.V):
            print("{0}\t\t{1}".format(i, distances[i]))

    def bellman_ford(self, source):

        distances = [float("Inf")] * self.V
        distances[source] = 0

        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if distances[u] != float("Inf") and distances[v] > distances[u] + w:
                    distances[v] = distances[u] + w

        for u, v, w in self.graph:
            if distances[u] != float("Inf") and distances[v] > distances[u] + w:
                print("Negative Cycle Detected!")
                return

        self._output(distances)

if __name__ == '__main__':
    graph = Graph(5)
    graph.add(0, 1, -1)
    graph.add(0, 2, 4)
    graph.add(1, 2, 3)
    graph.add(1, 3, 2)
    graph.add(1, 4, 2)
    graph.add(3, 2, 5)
    graph.add(3, 1, 1)
    graph.add(4, 3, -3)

    graph.bellman_ford(0)

