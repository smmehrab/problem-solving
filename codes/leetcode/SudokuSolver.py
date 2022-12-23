# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _valid_row(self, i, c):
        for j in range(9):
            if self.board[i][j] == c:
                return False
        return True
    
    def _valid_col(self, j, c):
        for i in range(9):
            if self.board[i][j] == c:
                return False
        return True

    def _valid_box(self, i, j, c):
        box_i = i - (i%3)
        box_j = j - (j%3)
        for i in range(box_i, box_i+3):
            for j in range(box_j, box_j+3):
                if self.board[i][j] == c:
                    return False
        return True

    def _valid(self, i, j, c):
        if self._valid_row(i, c) and self._valid_col(j, c) and self._valid_box(i, j, c):
            return True
        return False

    def _backtrack(self, i, j):
        # next empty space
        while self.board[i][j] != '.':
            j += 1
            if j == 9:
                i += 1
                j = 0
            if i == 9:
                return True
        # options
        for c in range(1, 10):
            if self._valid(i, j, str(c)):
                self.board[i][j] = str(c)
                if self._backtrack(i, j):
                    return True
        self.board[i][j] = '.'
        return False

    def solveSudoku(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        self._backtrack(0, 0)
