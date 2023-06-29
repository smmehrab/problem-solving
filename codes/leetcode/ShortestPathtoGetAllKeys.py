# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from typing import List
from collections import deque

class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:

        n = len(grid)
        m = len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        # set of state (position, keys_state, locks_state)
        visited = set()

        # number of keys and start position
        number_of_keys = 0
        start = None
        for i in range(n):
            for j in range(m):
                if grid[i][j] in 'abcdef':
                    number_of_keys += 1
                if grid[i][j] == '@':
                    start = (i, j)

        # goal state (keys)
        all_keys = 0
        for i in range(number_of_keys):
            all_keys ^= (1 << i)

        # BFS with state (position, keys_state, locks_state)
        level = 0
        queue = deque()
        queue.append((start, 0, 0))
        while queue:
            # process all nodes in this level
            for _ in range(len(queue)):
                state = queue.popleft()
                (i, j), keys, locks = state
                # goal reached
                if keys == all_keys:
                    return level
                # try all neighbors
                for (di, dj) in directions:
                    ni = i + di
                    nj = j + dj
                    # out of bound or wall
                    if not (0 <= ni < n and 0 <= nj < m) or grid[ni][nj] == '#':
                        continue
                    # locks
                    nlocks = locks
                    if grid[ni][nj] in "ABCDEF":
                        lock_index = ord(grid[ni][nj]) - ord("A")
                        if not (keys & (1 << lock_index)):
                            continue
                        nlocks |= 1 << i
                    # keys
                    nkeys = keys
                    if grid[ni][nj] in 'abcdef':
                        key_index = ord(grid[ni][nj]) - ord('a')
                        nkeys |= (1 << key_index)
                    # new state
                    nstate = ((ni, nj), nkeys, nlocks)
                    # visited
                    if nstate in visited:
                        continue
                    visited.add(nstate)
                    # add to queue
                    queue.append(nstate)
            level += 1

        return -1