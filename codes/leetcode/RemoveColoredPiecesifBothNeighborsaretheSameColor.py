# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def winnerOfGame(self, colors):
        """
        :type colors: str
        :rtype: bool
        """
        
        n = len(colors)
        removableAs = 0
        removableBs = 0
        
        for i in range(1, n-1):
            if colors[i] == 'A' and colors[i-1] == 'A' and colors[i+1] == 'A':
                removableAs += 1
            elif colors[i] == 'B' and colors[i-1] == 'B' and colors[i+1] == 'B':
                removableBs += 1
        
        return removableAs > removableBs
