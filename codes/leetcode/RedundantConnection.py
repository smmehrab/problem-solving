# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _union(self, x, y):
        root_x = self._find(x)
        root_y = self._find(y)
        # smallest = root
        if root_x > root_y:
            self.disjoint_set[root_x] = root_y
        else:
            self.disjoint_set[root_y] = root_x

    def _find(self, x):
        self.disjoint_set.setdefault(x, x)
        if x != self.disjoint_set[x]:
            self.disjoint_set[x] = self._find(self.disjoint_set[x])
        return self.disjoint_set[x]

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        self.disjoint_set = {}
        redundant = []
        for edge in edges:
            u, v = edge
            if self._find(u) == self._find(v):
                redundant = edge
            else:
                self._union(u, v)
        return redundant
