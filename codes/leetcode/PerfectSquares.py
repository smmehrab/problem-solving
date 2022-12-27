# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    """
        O(n*sqrt(n))
    """
    def numSquares(self, n: int) -> int:
        dp = [n]*(n+1)
        dp[0] = 0
        for i in range(1, n+1):
            option = 1
            option_square = (option*option)
            while option_square<=i:
                dp[i] = min(dp[i], 1+dp[i-option_square])
                option += 1
                option_square = (option*option)
        return dp[n]
