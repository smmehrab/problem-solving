# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class KMP:

    def __init__(self, pattern):
        self.pattern = pattern
        self.lps = [0]*len(pattern)
        self.computeLPS()
        pass

    def computeLPS(self):
        m = len(self.pattern)
        left = 0
        right = 1
        self.lps[left] = 0
        while right<m:
            if self.pattern[left] == self.pattern[right]:
                self.lps[right] = left+1
                left += 1
                right += 1
            else:
                if left != 0:
                    left = self.lps[left-1]
                else:
                    self.lps[right] = 0
                    right += 1

    def findPatternIn(self, text):
        indices = []

        n = len(text)
        m = len(self.pattern)
        tIndex = 0
        pIndex = 0
        while tIndex<n:
            if text[tIndex] == self.pattern[pIndex]:
                tIndex += 1
                pIndex += 1
            else:
                if pIndex!=0:
                    pIndex = self.lps[pIndex-1]
                else:
                    tIndex += 1
            if pIndex == m:
                indices.append(tIndex-pIndex)
                pIndex = self.lps[pIndex-1]

        return indices