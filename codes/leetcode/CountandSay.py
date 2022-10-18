# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    
    def say(self, s, n):
        
        n -= 1
        
        if n == 0:
            return s
        
        new_s = ""
        count = 0
        for (i, c) in enumerate(s):
            if i>0:
                if s[i-1] != s[i]:
                    new_s += str(count) + s[i-1]
                    count = 0
            count += 1

        new_s += str(count) + s[-1]
        return self.say(new_s, n)
    
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        return self.say("1", n)
