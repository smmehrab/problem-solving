# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Graph:

    def __init__(self, grid, obstacle:str="#", directions:list[tuple[int]]=[(0,1),(1,0),(0,-1),(-1,0)]) -> None:
        self.grid = grid
        self.n = len(self.grid)
        self.m = len(self.grid[0])
        self.obstacle = obstacle
        self.directions = directions
 
    def _visitable(self, cell):
        x, y = cell
        if x < 0 or y < 0 or x >= self.n or y >= self.m:
            return False
        if self.grid[x][y] == self.obstacle:
            return False
        return True

    def _exit(self, cell):
        x, y = cell
        if x==0 or y == 0 or x == (self.n-1) or y == (self.m-1):
            return True
        return False

    def bfs(self, source):
        nearest_exit = (self.n*self.m)

        x, y = source
        q = deque()

        level = 0
        q.append((source, level))
        self.grid[x][y] = self.obstacle

        while q:
            cell, level = q.popleft()
            x, y = cell
            # print(f"({x} {y}): {level}")

            if cell!=source and self._exit(cell):
                nearest_exit = min(nearest_exit, level)
                # print("Exit")

            for dx, dy in self.directions:
                neighbor = nx, ny = x+dx, y+dy
                if self._visitable(neighbor):
                    q.append((neighbor, level+1))
                    self.grid[nx][ny] = self.obstacle

        if nearest_exit == (self.n*self.m):
            nearest_exit = -1
        return nearest_exit
