# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        zero_count = 0
        longest_window = 0
        # sliding window
        left = 0
        for right in range(n):
            zero_count += (nums[right] == 0)
            while zero_count > 1:
                zero_count -= (nums[left] == 0)
                left += 1
            longest_window = max(longest_window, right - left)
        return longest_window