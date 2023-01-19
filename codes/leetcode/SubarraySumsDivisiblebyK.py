# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        subarray_count = 0
        prefix_sum_remainder = 0
        count = {}
        count[0] = 1
        for num in nums:
            prefix_sum_remainder = (prefix_sum_remainder + num) % k
            if prefix_sum_remainder not in count:
                count[prefix_sum_remainder] = 1
            else:
                subarray_count += count[prefix_sum_remainder]
                count[prefix_sum_remainder] += 1
        return subarray_count