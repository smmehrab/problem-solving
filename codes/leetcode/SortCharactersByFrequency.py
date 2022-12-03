# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def frequencySort(self, s: str) -> str:
        h = {}
        for c in s:
            if c not in h:
                h[c] = 1
            else:
                h[c] += 1

        sorted_h = sorted(h.items(), key = lambda x:x[1])[::-1]
        sorted_s = ""
        for c, count in sorted_h:
            sorted_s += (c*count)
        return sorted_s
