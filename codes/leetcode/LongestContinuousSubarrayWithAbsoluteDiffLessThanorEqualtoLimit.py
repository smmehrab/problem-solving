# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************


class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """

        DEBUG = True
        n = len(nums)
        left = 0
        right = 1
        diff = 0
        subarray_length = 1
        while right<n:
            if abs(diff + (nums[right]-nums[right-1])) <= limit:
                diff += (nums[right]-nums[right-1])
                right += 1
                subarray_length = max(subarray_length, (right-left))
                if DEBUG:
                    print(str(left) + " " + str(right-1) + " " + str(diff) + " (" + str(subarray_length) + ")")
            else:
                diff -= (nums[left+1]-nums[left])
                left += 1
        return subarray_length