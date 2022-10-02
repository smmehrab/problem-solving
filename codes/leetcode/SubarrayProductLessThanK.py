# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
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
        product = 1
        answer = 0

        while right<n:
            if product*nums[right]<k:
                product *= nums[right]
                right += 1
                answer += (right-left)
            else:
                if left == right:
                    left += 1
                    right += 1
                else:
                    product /= nums[left]
                    left += 1
            # print(product)
        return answer

