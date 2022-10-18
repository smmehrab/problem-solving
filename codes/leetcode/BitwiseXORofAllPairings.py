# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def xorAllNums(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        
        xor1 = 0
        for num in nums1:
            xor1 ^= num
            
        xor2 = 0
        for num in nums2:
            xor2 ^= num

        xor = 0
        
        if len(nums1)&1:
            xor ^= xor2
        
        if len(nums2)&1:
            xor ^= xor1
        
        return xor    
        