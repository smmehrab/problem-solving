# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, i, action):
        # Base
        if i>= self.n:
            return 0
        if (i, action) in self.dp:
            return self.dp[(i, action)]
        # Cooldown
        cooldown = self._dfs(i+1, action)
        # Selling
        if action == 1:
            sell = self._dfs(i+2, 1-action) + self.prices[i]
            self.dp[(i, action)] = max(sell, cooldown)
        # Buying
        else:
            buy = self._dfs(i+1, 1-action) - self.prices[i]
            self.dp[(i, action)] = max(buy, cooldown)
        return self.dp[(i, action)]

    def maxProfit(self, prices: list[int]) -> int:
        self.n = len(prices)
        self.prices = prices
        self.dp = {}
        return self._dfs(0, 0)


