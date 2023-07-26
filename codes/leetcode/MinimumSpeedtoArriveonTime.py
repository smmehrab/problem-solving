# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

import math

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        left, right = 1, 10**7
        min_speed = -1
        while left <= right:
            mid = (left + right) // 2
            # time required to travel at speed mid
            time = 0.0
            for i in range(n):
                t = dist[i] / mid
                time += (t if i == n-1 else math.ceil(t))
            # if its feasible
            if time <= hour:
                min_speed = mid
                right = mid - 1
            else:
                left = mid + 1
        return min_speed
