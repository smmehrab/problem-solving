# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        left = 0
        right = 0
        subarray_sum = 0
        subarray_len = n+1
        while right<n:
            subarray_sum += nums[right]
            while subarray_sum >= target:
                subarray_len = min(subarray_len, right-left+1)
                subarray_sum -= nums[left]
                left += 1
            right += 1

        subarray_len = 0 if subarray_len==n+1 else subarray_len
        return subarray_len
