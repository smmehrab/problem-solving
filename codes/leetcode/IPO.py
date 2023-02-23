# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capitals: List[int]) -> int:
        max_profit = []
        min_capital = []
        for capital, profit in zip(capitals, profits):
            min_capital.append((capital, profit))
        heapq.heapify(min_capital)

        for i in range(k):
            while min_capital and min_capital[0][0] <= w:
                capital, profit = heapq.heappop(min_capital)
                heapq.heappush(max_profit, profit*(-1))
            if max_profit:
                w += ((-1)*heapq.heappop(max_profit))
            else:
                break

        return w