# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def hierholzer(self, graph, start_node):
        if len(graph) == 0:
            return
        euler = []
        stack = [start_node]
        while stack:
            node = stack[-1]
            if node in graph and graph[node]:
                next_node = graph[node].pop(0)
                stack.append(next_node)
            else:
                euler.append(stack.pop())
        return euler[::-1]

    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = {}
        for ticket in tickets:
            if ticket[0] not in graph:
                graph[ticket[0]] = []
            graph[ticket[0]].append(ticket[1])

        for key, _ in graph.items():
            graph[key] = sorted(graph[key])

        eulerian_path = self.hierholzer(graph, "JFK")
        return eulerian_path