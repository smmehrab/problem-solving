# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        stack = deque()
        current_min = pow(10, 9) + 7

        for num in nums:
            # num is 3
            # finding 2
            while stack and num >= stack[-1][0]:
                stack.pop()
            # finding 1
            if stack and num > stack[-1][1]:
                return True
            # stacking 3 (possible 1 or 2 for the next 3s)
            stack.append((num, current_min))
            current_min = min(current_min, num)

        return False