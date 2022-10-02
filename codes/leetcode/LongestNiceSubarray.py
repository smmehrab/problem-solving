# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        nice = 1
        left = 0
        right = 1
        state = nums[0]
        while right<n:
            if state & nums[right]:
                state ^= nums[left]
                left += 1
            else:
                state ^= nums[right]
                nice = max(nice, right-left+1)
                right += 1
        return nice