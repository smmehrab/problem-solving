# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class DisjointSet():

    """
        UnionFind Algorithm
        Union - log(n)
        Find - log(n)
    """

    def __init__(self):
        self.parents = {}
        self.ranks = {}
        self.count = 0

    def find(self, u):
        while u != self.parents[u]: 
            # path compression
            self.parents[u] = self.parents[self.parents[u]]
            u = self.parents[u]
        return u

    def union(self, u, v):

        # new
        if u not in self.parents:
            self.parents[u] = u
            self.ranks[u] = 1
            self.count += 1

        if v not in self.parents:
            self.parents[v] = v
            self.ranks[v] = 1
            self.count += 1

        # rank optimization
        root_u = self.find(u)
        root_v = self.find(v)

        # already connected
        if root_u == root_v:
            return True

        # connect
        if self.ranks[root_u] > self.ranks[root_v]:
            self.parents[root_v] = root_u
        elif self.ranks[root_u] < self.ranks[root_v]:
            self.parents[root_u] = root_v
        else:
            self.parents[root_u] = root_v
            self.ranks[root_v] += 1
        self.count -= 1
        return False

    def connected(self, u, v):
        return self.find(u) == self.find(v)

    def get_count(self):
        return self.count


    # Only Functions
    # self.disjoint_set = {}

    # def _union(self, x, y):
    #     root_x = self._find(x)
    #     root_y = self._find(y)
    #     # smallest = root
    #     if root_x > root_y:
    #         self.disjoint_set[root_x] = root_y
    #     else:
    #         self.disjoint_set[root_y] = root_x

    # def _find(self, x):
    #     self.disjoint_set.setdefault(x, x)
    #     if x != self.disjoint_set[x]:
    #         self.disjoint_set[x] = self._find(self.disjoint_set[x])
    #     return self.disjoint_set[x]