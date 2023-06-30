
# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

# intuition:
# the last day when a land pathway exists from top to bottom 
# right before the first day when a water pathway exists from left to right

from typing import List

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

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        # 0 - land
        # 1 - water
        grid = [[0] * col for _ in range(row)]
        # water cells can be diagonal too
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        # disjoint set
        n = (row*col)
        disjoint_set = DisjointSet()
        for i in range(n+1):
            disjoint_set.union(i, i)
        # fill with water
        for i in range(n):
            r, c = cells[i][0] - 1, cells[i][1] - 1
            grid[r][c] = 1
            index = (r * col) + c
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < row and 0 <= nc < col and grid[nr][nc] == 1:
                    nindex = (nr * col) + nc
                    disjoint_set.union(index, nindex)
            if c == 0:
                disjoint_set.union(0, index)
            if c == col - 1:
                disjoint_set.union(n, index)
            if disjoint_set.connected(0, n):
                return i
        return -1