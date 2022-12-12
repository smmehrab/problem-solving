# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def climbStairs(self, n: int) -> int:
        f1, f2 = 1, 1
        n -= 2
        while n>=0:
            f3 = f1 + f2
            f2 = f1
            f1 = f3
            n -= 1
        return f1
