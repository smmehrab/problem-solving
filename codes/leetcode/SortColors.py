class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 0
        left = 0
        right = n-1
        
        while i<=right:
            if nums[i]==0:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1
                i += 1
            elif nums[i]==2:
                nums[right], nums[i] = nums[i], nums[right]
                right -= 1
            else:
                i += 1
                
        return nums