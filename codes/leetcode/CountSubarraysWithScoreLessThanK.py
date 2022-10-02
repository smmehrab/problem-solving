# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k==0:
            return 0
        
        n = len(nums)

        left = 0
        right = 0
        subarray_sum = 0
        subarray_count = 0

        while right<n:
            if (subarray_sum+nums[right])*(right-left+1)<k:
                subarray_sum += nums[right]
                right += 1
                subarray_count += (right-left)
            else:
                if left == right:
                    left += 1
                    right += 1
                else:
                    subarray_sum -= nums[left]
                    left += 1
        return subarray_count
