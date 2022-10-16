# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def maxCoins(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        
        piles.sort()
        
        n = len(piles)
        i = n-1
        low = (n//3)-1
        alt = 0
        coins = 0
        
        while i>low:
            if alt == 1:
                coins += piles[i]
            alt = 1-alt
            i -= 1
            
        return coins
