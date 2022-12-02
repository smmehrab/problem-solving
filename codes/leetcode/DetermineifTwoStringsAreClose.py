# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        f1 = [0]*26
        f2 = [0]*26
        base = ord('a')

        for c in word1:
            f1[ord(c)-base] += 1

        for c in word2:
            if f1[ord(c)-base]==0:
                return False
            f2[ord(c)-base] += 1

        f1.sort()
        f2.sort()

        for i in range(26):
            if f1[i]!=f2[i]:
                return False

        return True
