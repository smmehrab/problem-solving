# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution(object):
    def dfs(self, x, y):
        if x<0 or x>=self.m or y<0 or y>=self.n or self.grid[x][y]=="0":
            return
        self.grid[x][y] = "0"
        self.dfs(x+1, y)
        self.dfs(x-1, y)
        self.dfs(x, y+1)
        self.dfs(x, y-1)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.grid = grid
        self.n = len(grid[0])
        self.m = len(grid)
        islands = 0
        for y in range(self.n):
            for x in range(self.m):
                if grid[x][y] == "1":
                    self.dfs(x, y)
                    islands += 1
        return islands
