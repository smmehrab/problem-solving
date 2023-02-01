# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 == str2+str1:
            gcd = math.gcd(len(str1), len(str2))
            return str1[:gcd]
        return ""