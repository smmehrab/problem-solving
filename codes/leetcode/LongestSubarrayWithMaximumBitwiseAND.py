# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        num_max = max(nums)
        subarray = 0
        max_subarray = -1
        for num in nums:
            if num == num_max:
                subarray += 1
            else:
                max_subarray = max(max_subarray, subarray)
                subarray = 0

        max_subarray = max(max_subarray, subarray)
        return max_subarray
