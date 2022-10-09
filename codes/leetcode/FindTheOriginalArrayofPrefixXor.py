# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def findArray(self, pref):
        """
        :type pref: List[int]
        :rtype: List[int]
        """
        
        n = len(pref)
        local = 0
        xor = 0
        arr = [0]*n
        for i, num in enumerate(pref):
            local = (xor^num)
            xor ^= local
            arr[i] = local
            
        return arr
        