# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def breakPalindrome(self, palindrome):
        """
        :type palindrome: str
        :rtype: str
        """
        
        n = len(palindrome)
        if n==0 or n==1:
            return ""
        
        rc = 'a'
        modified = False
        for i, c in enumerate(palindrome):
            if c>rc and not (n&1 and i==(n//2)):
                palindrome = palindrome[:i] + rc + palindrome[i+1:]
                modified = True
                break
        
        if not modified:
            rc = 'b'
            palindrome = palindrome[:n-1] + rc
            
        return palindrome
        