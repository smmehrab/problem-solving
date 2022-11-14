# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class DisjointSet():

    """
        Union Find
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
