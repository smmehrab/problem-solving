# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def show_subarrays(self, start, end, nums):
        i = start
        while i<=end:
            print(nums[i]),
            i += 1
        print("")

    def getSubarrayCountWithAtmostKDistinct(self, nums, k, DEBUG):
        
        if k == 0:
            return 0
        
        n = len(nums)
        frequency = dict()
        distinct = 0
        left = 0
        right = 0
        subarray_count = 0

        if DEBUG:
            print("For k = " + str(k))
            print("---------------------------------------------")

        while right<n:
            if frequency.get(nums[right]) and frequency.get(nums[right])>0:
                frequency[nums[right]] += 1
            else:
                while distinct>=k:
                    frequency[nums[left]] -= 1
                    if frequency.get(nums[left])==0:
                        distinct -= 1
                    left += 1
                frequency[nums[right]] = 1
                distinct += 1

            if distinct <= k:
                subarray_count += (right-left+1)
                if DEBUG:
                    self.show_subarrays(left, right, nums)
            right += 1

        if DEBUG:
            print("---------------------------------------------")
            print("subarray_count = " + str(subarray_count))
            print("_____________________________________________")

        return subarray_count


    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        if k == 0:
            return 0

        DEBUG = False
        atmostK = self.getSubarrayCountWithAtmostKDistinct(nums, k, DEBUG)
        atmostKMinusOne = self.getSubarrayCountWithAtmostKDistinct(nums, k-1, DEBUG)
        
        return (atmostK - atmostKMinusOne)

