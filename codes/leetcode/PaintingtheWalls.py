# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import *

class Solution:

    def dfs(self, i, remaining):
        if remaining <= 0:
            return 0
        if i == self.n:
            return float('inf')
        if (i, remaining) in self.dp:
            return self.dp[(i, remaining)]

        paint = self.cost[i] + self.dfs(i+1, remaining-1-self.time[i])
        not_paint = self.dfs(i+1, remaining)
        self.dp[(i, remaining)] = min(paint, not_paint)
        return self.dp[(i, remaining)]

    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        self.n = len(cost)
        self.cost = cost
        self.time = time
        self.dp = {}
        return self.dfs(0, self.n)