# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from math import comb

class Solution:

    def solve(self, nums):
        if len(nums) <= 2:
            return 1

        left_subtree = []
        right_subtree = []
        for num in nums:
            if num < nums[0]:
                left_subtree.append(num)
            elif num > nums[0]:
                right_subtree.append(num)

        m = len(left_subtree)
        n = len(right_subtree)
        return comb(m+n, n) * self.solve(left_subtree) * self.solve(right_subtree)

    def numOfWays(self, nums: List[int]) -> int:
        return (self.solve(nums) - 1) % (10**9 + 7)
