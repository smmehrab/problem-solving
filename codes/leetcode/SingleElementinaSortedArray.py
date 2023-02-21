# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        single = 0
        for num in nums:
            single ^= num
        return single