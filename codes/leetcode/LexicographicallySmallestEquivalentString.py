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

    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        n = len(s1)
        self.disjoint_set = {}
        for i in range(n):
            self._union(s1[i], s2[i])

        smallest_equivalent_characters = []
        for c in baseStr:
            smallest_equivalent_characters.append(self._find(c))
        smallest_equivalent_string = ''.join(smallest_equivalent_characters)
        return smallest_equivalent_string