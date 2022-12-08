# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from functools import cmp_to_key

class GrahamScan:

    """
        Graham Scan Algorithm
        -   O(nlogn)
    """

    def __init__(self) -> None:
        self.sorting_reference = [0, 0]

    def _orientation(self, p1, p2, p3):
        # p3's orientation from (p1---p2)
        # 0 --> Colinear
        # 1 --> Clockwise
        # 2 --> Counterclockwise
        direction = ((p2[1]-p1[1]) * (p3[0]-p2[0]) - (p2[0]-p1[0]) * (p3[1]-p2[1]))
        if direction == 0:
            return 0
        elif direction > 0:
            return 1
        else:
            return 2

    def _distance_square(self, p1, p2):
        return ((p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]))

    def _compare(self, p1, p2):
        orientation = self._orientation(self.sorting_reference, p1, p2)
        if orientation == 0:
            if self._distance_square(self.sorting_reference, p2) >= self._distance_square(self.sorting_reference, p1):
                return -1
            else:
                return 1
        elif orientation == 1:
            return 1
        elif orientation == 2:
            return -1

    def solve(self, points):
        n = len(points)
        if n<3:
            return points

        # find source point
        ymin = points[0][1]
        ymin_index = 0
        for i in range(1, n):
            y = points[i][1]
            if ((y < ymin) or (ymin == y and points[i][0] < points[ymin_index][0])):
                ymin = points[i][1]
                ymin_index = i
        points[0], points[ymin_index] = points[ymin_index], points[0]

        # sort according to polar angle (increasing order)
        self.sorting_reference = points[0]
        points = sorted(points, key=cmp_to_key(self._compare))

        # find convex hull
        convex_hull = []
        convex_hull.append(points[0])
        convex_hull.append(points[1])
        convex_hull.append(points[2])
        for i in range(3, n):
            while len(convex_hull)>1 and self._orientation(convex_hull[-2], convex_hull[-1], points[i]) == 1:
                convex_hull.pop()
            convex_hull.append(points[i])

        # add colinear points too
        nh = len(convex_hull)
        i = ci = 1
        while i<n:
            if points[i] == convex_hull[ci]:
                ci += 1
            else:
                if ci == nh-1:
                    if self._orientation(convex_hull[0], convex_hull[ci], points[i]) == 0:
                        convex_hull.append(points[i])
                elif self._orientation(convex_hull[ci-1], convex_hull[ci], points[i]) == 0:
                    convex_hull.append(points[i])
            i += 1

        return convex_hull

class Solution:
    def outerTrees(self, trees: list[list[int]]) -> list[list[int]]:
        return GrahamScan().solve(trees)
