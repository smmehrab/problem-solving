# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        hash_map = dict()
        hash_map[0] = -1
        
        csum = 0
        for index, num in enumerate(nums):
            csum += num
            remainder = (csum % k)
            if remainder not in hash_map:
                hash_map[remainder] = index
            elif (index-hash_map[remainder]) >= 2:
                return True
            
        return False
