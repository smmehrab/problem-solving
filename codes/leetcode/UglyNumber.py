# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def isUgly(self, n: int) -> bool:
        if n!=0:
            factors = [2, 3, 5]
            for factor in factors:
                while n % factor == 0:
                    n /= factor
                if n == 1:
                    break
        return n==1