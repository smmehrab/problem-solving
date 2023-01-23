# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1:
            return 1

        trusting = [0]*n 
        trusted = [0]*n 

        for a, b in trust:
            trusting[a-1] += 1
            trusted[b-1] += 1

        for i in range(n):
            if trusting[i] == 0 and trusted[i] == n-1:
                return i+1

        return -1
