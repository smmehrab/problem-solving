# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        
        m = (10**9) + 7
        arr.sort()
        number_of_binary_trees = 0

        n = len(arr)
        dp = [1]*n
        for i in range(n):
            for j in range(i):
                if arr[i]%arr[j]==0:
                    if arr[i]//arr[j] in arr:
                        factor1 = arr[j]
                        factor2 = arr[i]//arr[j]
                        index1 = arr.index(factor1)
                        index2 = arr.index(factor2)
                        dp[i] += (dp[index1]*dp[index2])
            number_of_binary_trees += dp[i]
        return number_of_binary_trees%m