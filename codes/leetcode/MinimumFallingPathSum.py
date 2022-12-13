# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def minFallingPathSum(self, dp: list[list[int]]) -> int:
        # top down
        n = len(dp)
        for i in range(1, n): 
            for j in range(n):
                if j==0:
                    dp[i][j] += min(dp[i-1][j], dp[i-1][j+1])
                elif j==n-1:
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j])
                else:
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
        return min(dp[-1])
