# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        if not mat or not mat[0]:
            return []

        n = len(mat)
        m = len(mat[0])
        max_distance = m * n
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        # Multi-Source
        queue = deque()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    queue.append((i, j))
                else:
                    mat[i][j] = max_distance

        # BFS
        while queue:
            r, c = queue.popleft()
            for dr, dc in directions:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < n and 0 <= nc < m and mat[nr][nc] > mat[r][c] + 1:
                    queue.append((nr, nc))
                    mat[nr][nc] = mat[r][c] + 1

        return mat