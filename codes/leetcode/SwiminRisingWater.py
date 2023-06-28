# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from heapq import heappush, heappop

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visited = set()
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        pq = [(grid[0][0], (0, 0))]
        visited.add((0, 0))
        while pq: 
            max_height, (i, j) = heappop(pq)
            if i == j == n-1: 
                return max_height
            for di, dj in directions:
                new_i, new_j = i+di, j+dj
                neighbor = (new_i, new_j)
                if 0 <= new_i < n and 0 <= new_j < n and neighbor not in visited:
                    max_height_on_path = max(max_height, grid[new_i][new_j])
                    heappush(pq, (max_height_on_path, neighbor))
                    visited.add(neighbor)
        return -1