# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def findWinners(self, matches: list[list[int]]) -> list[list[int]]:

        # init
        pmax = -1
        for winner, loser in matches:
            pmax = max(pmax, max(winner, loser))
        prange = pmax+1
        pstatus = [0]*prange

        # count
        for winner, loser in matches:
            # no loss
            if pstatus[winner]==0:
                pstatus[winner] = 1
            # first loss
            if pstatus[loser]>=0:
                pstatus[loser] = -1
            # multiple loss
            elif pstatus[loser]<0:
                pstatus[loser] -= 1

        # retrieve info
        zero_loss = []
        one_loss = []
        for index, status in enumerate(pstatus):
            if status == 1:
                zero_loss.append(index)
            elif status == -1:
                one_loss.append(index)

        return [zero_loss, one_loss]
