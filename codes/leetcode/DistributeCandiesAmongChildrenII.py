# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ways = 0
        for c1 in range(min(n, limit) + 1):
            remaining = n - c1
            c2 = max(remaining - limit, 0)
            c3 = min(remaining, limit)
            if c2 <= c3:
                ways += (c3 - c2 + 1)
        return ways