# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def get_final_string(self, x):
        final_string = []
        for c in x:
            if c != '#':
                final_string.append(c)
            elif final_string:
                final_string.pop()
        return "".join(final_string)

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.get_final_string(s) == self.get_final_string(t)