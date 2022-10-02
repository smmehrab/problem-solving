# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        n = len(cards)
        occurred = dict()
        pick = n+1
        for index, card in enumerate(cards):
            if card in occurred:
                pick = min(pick, (index-occurred.get(card)+1))
            occurred[card] = index
            
        pick = -1 if pick==n+1 else pick
        return pick