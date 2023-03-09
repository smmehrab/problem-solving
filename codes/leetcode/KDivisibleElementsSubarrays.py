# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def show_subarrays(self, start, end, nums, divisibles):
        print("(" + str(divisibles) + ")")
        i = start
        while i<=end:
            print(nums[i]),
            i += 1
        print("")

    def getSubarrayCountWithAtmostKDivisibles(self, nums, k, p, DEBUG):

        if k == 0:
            return 0

        n = len(nums)
        left = 0
        right = 0
        divisibles = 0
        subarray_count = 0

        frequency = dict()

        if DEBUG:
            print("For k = " + str(k))
            print("---------------------------------------------")

        while right<n:
            if frequency.get(nums[right]):
                frequency[nums[right]] += 1
            else:
                frequency[nums[right]] = 1

            if nums[right]%p == 0:
                while divisibles>=k:
                    if nums[left]%p == 0:
                        divisibles -= 1
                    left += 1
                divisibles += 1

            if divisibles <= k:
                subarray_count += (right-left+1)
                if DEBUG:
                    self.show_subarrays(left, right, nums, divisibles)
                    print("[" + str((right-left+1)) + "]")
            right += 1

        for value in frequency.values():
            subarray_count -= (value-1)

        if DEBUG:
            print("---------------------------------------------")
            print("subarray_count = " + str(subarray_count))
            print("_____________________________________________")
            
        return subarray_count


    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        return self.getSubarrayCountWithAtmostKDivisibles(nums, k, p, True)
