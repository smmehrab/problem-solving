# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        min_cost = 0
        prev1, prev2 = 0, 0
        for i in range(2, n + 1):
            min_cost = min(prev1 + cost[i-1], prev2 + cost[i-2])
            prev2, prev1 = prev1, min_cost
        return min_cost