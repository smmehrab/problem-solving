# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from heapq import heappop, heappush, heapify

class Solution:
    def minStoneSum(self, piles: list[int], k: int) -> int:
        heap = []
        heapify(heap)
        for pile in piles:
            heappush(heap, (-1) * pile)

        for i in range(k):
            max_pile = (-1)*heappop(heap)
            print(max_pile)
            max_pile -= (max_pile//2)
            heappush(heap, (-1) * max_pile)

        stones = 0
        for element in heap:
            stones += (-1)*element
        return stones