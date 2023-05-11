# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)

        if n1 < n2:
            nums1, nums2 = nums2, nums1
            n1, n2 = n2, n1

        # Space
        # Instead of O(n1*n2)
        # O(2*n2)
        # Two rows to work with
        dp = [[0] * (n2+1) for _ in range(2)]
        for i in range(n1):
            row = (i+1)%2
            prev_row = i%2
            for j in range(n2):
                if nums1[i] == nums2[j]:
                    dp[row][j+1] = 1 + dp[prev_row][j]
                else:
                    dp[row][j+1] = max(dp[row][j], dp[prev_row][j+1])

                # print("-------------")
                # print(dp[prev_row])
                # print(dp[row])

        return max(dp[0][n2], dp[1][n2])