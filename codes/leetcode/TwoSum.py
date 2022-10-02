# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        n = len(nums)
        indices = dict()
        
        index = 0
        for num in nums:
            indices[num] = index
            index += 1
        
        index = 0
        for num in nums:
            if (target-num) in indices:
                if index != indices.get(target-num):
                    return [index, indices.get(target-num)]
            index += 1
            
        return []
