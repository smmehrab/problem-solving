# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        f = {}
        for num in arr:
            if num not in f:
                f[num] = 1
            else:
                f[num] += 1

        ff = {}
        for key in f:
            if f[key] not in ff:
                ff[f[key]] = 1
            else:
                return False
        return True
