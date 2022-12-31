# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, x, y, empty_cells):
        if x<0 or y<0 or x>=self.n or y>=self.m or self.grid[x][y] == -1:
            return 0
        elif self.grid[x][y] == 2:
            return empty_cells == -1
        self.grid[x][y] = -1
        path_count = self._dfs(x+1, y, empty_cells-1)
        path_count += self._dfs(x, y+1, empty_cells-1)
        path_count += self._dfs(x-1, y, empty_cells-1)
        path_count += self._dfs(x, y-1, empty_cells-1)
        self.grid[x][y] = 0
        return path_count

    def uniquePathsIII(self, grid: list[list[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        self.grid = grid
        x, y, empty_cells = 0, 0, 0
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == 0:
                    empty_cells += 1
                elif grid[i][j] == 1:
                    x, y = i, j
        return self._dfs(x, y, empty_cells)
