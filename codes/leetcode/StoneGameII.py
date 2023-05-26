# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def dfs(self, turn, i, M):
        if i == self.n:
            return 0

        if (turn, i, M) in self.dp:
            return self.dp[(turn, i, M)]
        
        alice_max = 0 if turn else float('inf')
        stones = 0
        for X in range(1, 2*M+1):
            if i+X > self.n:
                break
            stones += self.piles[i+X-1]
            # Alice
            if turn:
                alice_max = max(alice_max, stones + self.dfs(not turn, i+X, max(M, X)))
            # Bob
            else:
                alice_max = min(alice_max, self.dfs(not turn, i+X, max(M, X)))

        self.dp[(turn, i, M)] = alice_max
        return alice_max

    def stoneGameII(self, piles: List[int]) -> int:
        self.piles = piles
        self.n = len(piles)
        self.dp = {}
        return self.dfs(True, 0, 1)