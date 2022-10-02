# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        
        if n==0:
            return 0

        ans = 1
        left = 0
        right = 0
        included = set()

        while right<n:
            if s[right] in included:
                included.discard(s[left])
                left += 1
            else:
                included.add(s[right])
                right += 1
                ans = max(ans, right-left)
        return ans