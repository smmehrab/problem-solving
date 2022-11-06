# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        ordered = s
        if k==1:
            n = len(s)
            for i in range(n):
                rotated = s[i:n:]+s[0:i:]
                ordered = min(ordered, rotated)
        else:
            ordered = ''.join(sorted(ordered))
        return ordered
