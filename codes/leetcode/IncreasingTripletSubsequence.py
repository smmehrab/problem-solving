# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        if len(nums)<3:
            return False
        
        INF = 2147483648
        left = INF
        mid = INF
        
        for num in nums:
            
            if left>=num:
                left = num
            elif mid>=num:
                mid = num
            else:
                return True
            
        return False