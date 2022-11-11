# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        u_index = 1
        for (i, num) in enumerate(nums):
            if i!=0 and nums[i] != nums[i-1]:
                nums[u_index] = nums[i]
                u_index += 1
        return u_index
