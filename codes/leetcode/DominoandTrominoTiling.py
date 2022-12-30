# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def numTilings(self, n: int) -> int:
        m = (10**9)+7
        dp = [0]*1010
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        if n>2:
            for i in range(3, n+1):
                dp[i] = ((2*dp[i-1]) + dp[i-3])%m
        return dp[n]

        # not working
        m = (10^9)+7
        dp = [[0]*4]*(n+2)
        dp[0][3] = 1
        dp[1][0] = 1
        dp[1][1] = 0
        dp[1][2] = 0
        dp[1][3] = 1
        for i in range(2, n+1):
            # State 0
            dp[i][0] += dp[i-1][3]
            # State 1
            dp[i][1] += dp[i-2][3]
            dp[i][1] += dp[i-1][2]
            # State 2
            dp[i][2] += dp[i-2][3]
            dp[i][2] += dp[i-1][1]
            # State 3
            dp[i][3] += dp[i-1][1]
            dp[i][3] += dp[i-1][2]
            dp[i][3] += dp[i-1][3]
        return dp[n][3]%m