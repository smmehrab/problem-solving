# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class DisjointSet():

    def __init__(self, n=None):
        self.parents = {}
        self.ranks = {}

        if n:
            for i in range(n):
                self.union(i, i)

    def find(self, u):
        while u != self.parents[u]: 
            self.parents[u] = self.parents[self.parents[u]]
            u = self.parents[u]
        return u

    def union(self, u, v):

        if u not in self.parents:
            self.parents[u] = u
            self.ranks[u] = 1

        if v not in self.parents:
            self.parents[v] = v
            self.ranks[v] = 1

        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return False

        if self.ranks[root_u] > self.ranks[root_v]:
            self.parents[root_v] = root_u
        elif self.ranks[root_u] < self.ranks[root_v]:
            self.parents[root_u] = root_v
        else:
            self.parents[root_u] = root_v
            self.ranks[root_v] += 1
        return True

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:

        for index, edge in enumerate(edges):
            edge.append(index)
        edges.sort(key=lambda x: x[2])

        disjoint_set = DisjointSet(n)
        mst = 0
        for u, v, w, i in edges:
            if disjoint_set.union(u, v):
                mst += w
        print(mst)
        print("-----")

        critical, pseudo_critical = [], []
        for u, v, w, i in edges:
            # check critical
            tmp_disjoint_set = DisjointSet(n)
            tmp_mst = 0
            for x, y, z, j in edges:
                if i!=j and tmp_disjoint_set.union(x, y):
                    tmp_disjoint_set.union(x, y)
                    tmp_mst += z
            print(i)
            print(mst)
            print(tmp_mst)
            print(max(tmp_disjoint_set.ranks))
            print("------")
            if max(tmp_disjoint_set.ranks)!=n-1 or tmp_mst > mst:
                critical.append(i)
                continue
            # check pseudo critical
            tmp_disjoint_set = DisjointSet(n)
            tmp_disjoint_set.union(u, v)
            tmp_mst = w
            for x, y, z, j in edges:
                if tmp_disjoint_set.union(x, y):
                    tmp_mst += z
            if tmp_mst == mst:
                pseudo_critical.append(i)

        return [critical, pseudo_critical]