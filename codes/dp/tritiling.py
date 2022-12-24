# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

def solve(n):
    dp = [[0]*8]*(n+1)
    dp[0][7] = 1
    for i in range(1, n+1):
        # State 0
        dp[i][0] += dp[i-1][7]
        # State 1
        dp[i][1] += dp[i-1][6]
        # State 2
        # dp[i][2] += dp[i-1][5];
        # State 3
        dp[i][3] += dp[i-1][7]
        dp[i][3] += dp[i-1][4]
        # State 4
        dp[i][4] += dp[i-1][3]
        # State 5
        # dp[i][5] += dp[i-1][2];
        # State 6
        dp[i][6] += dp[i-1][7]
        dp[i][6] += dp[i-1][1]
        # State 7
        dp[i][7] += dp[i-1][3]
        dp[i][7] += dp[i-1][6]
        dp[i][7] += dp[i-1][0]
    return dp[n][7]
