# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def makeGood(self, s: str) -> str:
        gs = []
        for c in s:
            if not gs:
                gs.append(c)
            elif gs[-1].lower() == c.lower() and gs[-1] != c:
                gs.pop()
            else:
                gs.append(c)
        return ''.join(gs)
