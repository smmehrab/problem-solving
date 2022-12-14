# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n>1:
            nums[1] = max(nums[0], nums[1])
            for i in range(2, n):
                nums[i] = max(nums[i]+nums[i-2], nums[i-1])
        return nums[n-1]
