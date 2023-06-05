# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class Solution:
    def dfs(self, i):
        self.visited[i] = True
        for j in range(self.n):
            if self.is_connected[i][j] == 1 and not self.visited[j]:
                self.dfs(j)

    def findCircleNum(self, isConnected):
        self.n = len(isConnected)
        self.is_connected = isConnected
        self.visited = [False] * self.n
        provinces = 0
        for i in range(self.n):
            if not self.visited[i]:
                provinces += 1
                self.dfs(i)
        return provinces