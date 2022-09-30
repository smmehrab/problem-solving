# **************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   smmehrabul-2017614964@cs.du.ac.bd
# institute   :   university of dhaka, bangladesh
# reg         :   2017614964
# **************************************************

    
class Solution(object):
    
    def getLPS(self, s):
        m = len(s)
        lps = [0]*len(s)
        left = 0
        right = 1
        lps[left] = 0
        while right<m:
            if s[left] == s[right]:
                lps[right] = left+1
                left += 1
                right += 1
            else:
                if left != 0:
                    left = lps[left-1]
                else:
                    lps[right] = 0
                    right += 1
        # print(lps)
        return lps[m-1]
                    
    def longestPrefix(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = self.getLPS(s)
        return s[:i]
