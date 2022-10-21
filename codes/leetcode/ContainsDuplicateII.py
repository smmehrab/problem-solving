# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:

        num_indices = dict()
        for index, num in enumerate(nums):
            if num in num_indices:
                if index - num_indices[num] <= k:
                    return True
            num_indices[num] = index

        return False
