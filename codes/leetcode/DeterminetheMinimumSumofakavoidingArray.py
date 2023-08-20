# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        if k == 0:
            return n * (n + 1) // 2
    
        min_sum = 0
        i = 1
        count = 0
        while count < n:            
            if i > (k//2) and i<k:
                i = k
            min_sum += i
            count += 1
            i += 1

        return min_sum