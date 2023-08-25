# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        longest_equal_subarray = -1
        count = {}
        left = 0

        for right in range(n):
            num = nums[right]
            count[num] = count.get(num, 0) + 1

            total_deletions = (right - left + 1) - max(count.values())

            while total_deletions > k:
                left_num = nums[left]
                count[left_num] -= 1
                if count[left_num] == 0:
                    del count[left_num]
                left += 1
                total_deletions = (right - left + 1) - max(count.values())

            longest_equal_subarray = max(longest_equal_subarray, max(count.values()))

        return longest_equal_subarray
