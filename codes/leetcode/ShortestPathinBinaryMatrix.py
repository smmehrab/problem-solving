# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)

        if grid[0][0]==1 or grid[n - 1][n - 1]==1:
            return -1

        directions = [
            (-1, -1), (-1, 0), (-1, +1),
            (0, -1), (0, + 1),
            (+1, -1), (+1, 0), (+1, +1)
        ]

        queue = deque()
        queue.append((0, 0, 1))
        grid[0][0] = 1

        while queue:
            x, y, d = queue.popleft()

            if x == n-1 and y == n-1:
                return d

            for i, j in directions:
                xi = x+i
                yj = y+j
                if 0 <= xi < n and 0 <= yj < n and grid[xi][yj]==0:
                    grid[xi][yj] = 1
                    queue.append((xi, yj, d+1))

        return -1