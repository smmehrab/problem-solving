# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prices = [float("inf")]*n
        prices[src] = 0
        for i in range(k+1):
            tmp = prices.copy()
            for u, v, w in flights:
                if prices[u] == float("inf"):
                    continue
                elif tmp[v] > prices[u] + w:
                    tmp[v] = prices[u] + w
            prices = tmp
        cheapest_price = -1 if prices[dst] == float("inf") else prices[dst]
        return cheapest_price
