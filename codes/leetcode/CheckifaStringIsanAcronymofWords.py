# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************
class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        a = ""
        for word in words:
            a += word[0]
        return a == s
        