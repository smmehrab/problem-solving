# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import defaultdict

class MaxColinearPointsFinder:

    def __init__(self) -> None:
        pass

    def _get_line(x0, y0, x1, y1):
        if y0 == y1:
            return (0, y0)
        if x0 == x1:
            return (x0, None)
        else:
            slope = (y1-y0)/(x1-x0)
            intercept = y0 - (slope*x0)
            return slope, intercept

    def find(self, points:list[list]):
        n = len(points)
        if n==1:
            return n

        lines = defaultdict(lambda:set())
        for i in range(0, n):
            for j in range(i+1, n):
                x0, y0 = points[i]
                x1, y1 = points[j]
                line = self._get_line(x0, y0, x1, y1)
                lines[line].add(i)
                lines[line].add(j)

        return max([len(lines[line]) for line in lines])
