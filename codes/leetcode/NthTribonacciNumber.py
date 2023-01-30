# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def tribonacci(self, n: int) -> int:
        t = [0]*max(3, n+1)
        t[1] = 1
        t[2] = 1
        for i in range(3, n+1):
            t[i] = t[i-1] + t[i-2] + t[i-3]
        return t[n]