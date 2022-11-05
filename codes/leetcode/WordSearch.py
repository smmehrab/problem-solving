# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def dfs(self, node, match_count):
        # match
        if match_count == self.word_length:
            return True

        x, y = node
        # out of bound
        if x<0 or y<0 or x>=self.n or y>=self.m:
            return False
        # mismatch
        if self.word[match_count] != self.graph[x][y]:
            return False
        # already checked
        if node in self.visited:
            return False

        # backtracking
        self.visited.add(node)
        is_matched = (self.dfs((x+1, y), match_count+1) or
                      self.dfs((x-1, y), match_count+1) or
                      self.dfs((x, y+1), match_count+1) or
                      self.dfs((x, y-1), match_count+1))
        self.visited.remove(node)
        return is_matched

    def exist(self, board: list[list[str]], word: str) -> bool:
        self.word_length = len(word)
        self.word = word
        self.n = len(board)
        self.m = len(board[0])
        self.graph = board

        if self.word_length > (self.n*self.m):
            return False

        # brute-force dfs
        self.visited = set()
        for i in range(self.n):
            for j in range(self.m):
                if self.word[0] == self.graph[i][j]:
                    if self.dfs((i, j), 0):
                        return True

        return False
