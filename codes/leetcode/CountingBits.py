# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def countBits(self, n: int) -> list[int]:
        dp = [0]*(n+1)
        offset = 1
        for i in range(1, n+1):
            if (offset*2) == i:
                offset = i
            dp[i] = 1 + dp[i-offset]
        return dp