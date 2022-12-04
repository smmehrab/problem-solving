# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def minimumAverageDifference(self, nums: list[int]) -> int:

        n = len(nums)
        total = sum(nums)
        left_sum = 0
        right_sum = 0
        min_avg_diff = float("inf")
        min_avg_diff_index = -1

        for i, num in enumerate(nums):
            left_sum += num
            right_sum = total-left_sum
            left_avg = left_sum // (i+1)
            right_avg = 0 if i == n-1 else right_sum // (n-1-i)
            avg_diff = abs(left_avg-right_avg)

            if avg_diff < min_avg_diff:
                min_avg_diff_index = i
                min_avg_diff = avg_diff

        return min_avg_diff_index
