class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        left = 0
        right = 0
        window = 0

        while right<n:
            # expand window to right --> 
            if nums[right]==0:
                k -= 1
            right += 1
            # --> shrink window from left            
            if k<0:
                if nums[left] == 0:
                    k += 1
                left += 1
            window = max(window, right-left)

        return window