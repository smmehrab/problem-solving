# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, node, path):
        if node == self.n - 1:
            self.paths.append(path)
        else:
            for neighbor in self.graph[node]: 
                self._dfs(neighbor, path + [neighbor])

    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
        self.n = len(graph)
        self.graph = graph
        self.paths = []
        self._dfs(0, [0])
        return self.paths