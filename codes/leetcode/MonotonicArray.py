# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        n = len(nums)
        monotonic = True
        monotone = None
        for i in range(1, n):
            if nums[i] == nums[i-1]:
                continue
            elif not monotone:
                monotone = 1 if nums[i]>nums[i-1] else -1
            valid = (monotone * (nums[i]-nums[i-1])) >= 0
            monotonic = monotonic and valid
        return monotonic