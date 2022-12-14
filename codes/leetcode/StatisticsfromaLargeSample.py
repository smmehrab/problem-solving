# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

import math

class Solution:
    def sampleStats(self, count: list[int]) -> list[float]:
        statistics = []
        minimum = -1
        maximum = -1
        mean = 0
        median = -1
        mode = -1

        # first pass
        n = 0
        for i in range(256):
            if count[i]>0:
                n += count[i]
                if minimum == -1:
                    minimum = i
                if mode ==-1 or count[i]>count[mode]:
                    mode = i
                maximum = i
                mean += (i*count[i])
        mean /= n

        # second pass (for median)
        n_mid = math.ceil((n+1)/2)
        interpolate = ((n+1)/2 != n_mid)
        n = 0
        previous = 0
        for i in range(256):
            if count[i]>0:
                n += count[i]
                if median == -1 and n >= n_mid:
                    if interpolate and n_mid-(n-count[i])==1:
                        median = ((previous+i)/2)
                    else:
                        median = i
                    break
                previous = i

        statistics.append(minimum)
        statistics.append(maximum)
        statistics.append(mean)
        statistics.append(median)
        statistics.append(mode)
        return statistics