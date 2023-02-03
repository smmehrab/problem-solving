# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def convert(self, s: str, n: int) -> str:
        if n == 1 or n >= len(s):
            return s

        S = [""] * n
        i, d = 0, 1

        for c in s:
            S[i] += c
            if i == 0:
                d = 1
            elif i == n-1:
                d = -1
            i += d
        return ''.join(S)