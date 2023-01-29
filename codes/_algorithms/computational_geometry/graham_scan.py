# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from functools import cmp_to_key

class Point:
    def __init__(self, x=None, y=None):
        self.x = x
        self.y = y

class GrahamScan:

    """
        Graham Scan Algorithm
        -   O(nlogn)
    """

    def __init__(self) -> None:
        self.sorting_reference = Point(0, 0)
        self.DEBUG = False

    def _orientation(self, p1, p2, p3):
        # p3's orientation from (p1---p2)
        # 0 --> Colinear
        # 1 --> Clockwise
        # 2 --> Counterclockwise
        direction = ((p2.y-p1.y) * (p3.x-p2.x) - (p2.x-p1.x) * (p3.y-p2.y))
        if direction == 0:
            return 0
        elif direction > 0:
            return 1
        else:
            return 2

    def _distance_square(self, p1, p2):
        return ((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y))

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
            return ["Not Enough Points"]

        # find source point
        ymin = points[0].y
        ymin_index = 0
        for i in range(1, n):
            y = points[i].y
            if ((y < ymin) or (ymin == y and points[i].x < points[ymin_index].x)):
                ymin = points[i].y
                ymin_index = i
        points[0], points[ymin_index] = points[ymin_index], points[0]

        # sort according to polar angle (increasing order)
        self.sorting_reference = points[0]
        points = sorted(points, key=cmp_to_key(self._compare))

        if self.DEBUG:
            print(f"Source: ({points[0][0]}, {points[0][1]})")
            print("Sorted on Polar Angle (Increasing)")
            for point in points:
                print(f"({point[0]}, {point[1]})")

        # eliminate colinear points
        index = 1
        modified_index = index
        while index<n:
            while index<(n-1) and self._orientation(points[0], points[index], points[index+1]) == 0:
                index += 1
            points[modified_index] = points[index]
            modified_index += 1
            index += 1

        n = modified_index
        if n<3:
            return ["Not Enough Non-Colinear Points"]

        # find convex hull
        convex_hull = []
        convex_hull.append(points[0])
        convex_hull.append(points[1])
        convex_hull.append(points[2])
        for i in range(3, n):
            while len(convex_hull)>1 and self._orientation(convex_hull[-2], convex_hull[-1], points[i]) != 2:
                convex_hull.pop()
            convex_hull.append(points[i])
        return convex_hull
