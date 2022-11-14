# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class DisjointSet():

    def __init__(self, N):
        self.parents = [node for node in range(N)]
        self.ranks = [1 for _ in range(N)]

    def find(self, u):
        while u != self.parents[u]: 
            # path compression
            self.parents[u] = self.parents[self.parents[u]]
            u = self.parents[u]
        return u

    def union(self, u, v):
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
        return False

    def connected(self, u, v):
        return self.find(u) == self.find(v)
