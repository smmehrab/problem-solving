# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict
from queue import PriorityQueue

class Graph:

    """
        Dijkstra Algorithm
        O(E * logV)
    """

    def __init__(self, number_of_vertices):
        self.graph = defaultdict(list)
        self.V = number_of_vertices

    def add(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))

    def _output(self, distances):
        print("{0}\t\t{1}".format("Vertex", "Distance"))
        for i in range(self.V):
            print("{0}\t\t{1}".format(i, distances[i]))

    def dijkstra(self, source):
        distances = [float("Inf")] * self.V
        distances[source] = 0

        pq = PriorityQueue()
        pq.put((0, source))

        while not pq.empty():
            priority_d, u = pq.get()
            for v, w in self.graph[u]:
                if distances[v] > distances[u] + w:
                    distances[v] = distances[u] + w
                    pq.put((distances[v], v))
        self._output(distances)
        return distances

if __name__ == '__main__':

    graph = Graph(9)

    graph.add(0, 1, 4)
    graph.add(0, 7, 8)
    graph.add(1, 2, 8)
    graph.add(1, 7, 11)
    graph.add(2, 3, 7)
    graph.add(2, 8, 2)
    graph.add(2, 5, 4)
    graph.add(3, 4, 9)
    graph.add(3, 5, 14)
    graph.add(4, 5, 10)
    graph.add(5, 6, 2)
    graph.add(6, 7, 1)
    graph.add(6, 8, 6)
    graph.add(7, 8, 7)
 
    graph.dijkstra(0)