# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts = [0] + sorted(cuts) + [n]
        cuts_count = len(cuts)

        @lru_cache(None)
        def find_min_cost(l, r):
            if r - l == 1:
                return 0
            min_cut_cost = float('inf')
            for i in range(l+1, r):
                cut_cost = cuts[r] - cuts[l]
                cut_cost += find_min_cost(l, i)
                cut_cost += find_min_cost(i, r)
                min_cut_cost = min(min_cut_cost, cut_cost)
            return min_cut_cost

        return find_min_cost(0, cuts_count - 1)