# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        left = 1
        right = sum(batteries) // n

        while left < right:
            mid = right - (right - left) // 2
            
            utilized = 0
            for battery in batteries:
                utilized += min(battery, mid)

            minutes = (utilized // n)
            if minutes >= mid:
                left = mid
            else:
                right = mid - 1
        
        return left
