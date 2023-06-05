# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        nodes = []
        for index, [x,y] in enumerate(points):
            d = ((x**2) + (y**2))
            heapq.heappush(nodes,(d*(-1), index))
            if len(nodes) > k:
                heapq.heappop(nodes)
        return [points[index] for d, index in nodes]
