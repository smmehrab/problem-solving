# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):

    def solveUsingSlidingWindow(self, target, nums):
        """
            O(n)
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

    def binarySearch(self, x, array, low, high):
        while low <= high:
            mid = low + (high - low)//2
            if array[mid] == x:
                return mid
            elif array[mid] < x:
                low = mid + 1
            else:
                high = mid - 1
        return -1

    def solveUsingBinarySearch(self, target, nums):
        """
            O(nlog(n))
        """
        n = len(nums)
        if n==0:
            return 0
        
        subarray_len = n+1
        sums = [0]*n

        sums[0] = nums[0]
        index = 1
        while index<n:
            sums[index] = sums[index-1] + nums[index]

        index = 1
        while 

        return subarray_len

    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        # min_subarray_len = self.solveUsingBinarySearch(target, nums)
        min_subarray_len = self.solveUsingSlidingWindow(target, nums)
        return min_subarray_len
