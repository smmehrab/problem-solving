# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = {}
        dp[0] = 1
        for i in range(1, target+1):
            dp[i] = 0
            for num in nums:
                if i-num in dp:
                    dp[i] += dp[i-num]
        return dp[target]