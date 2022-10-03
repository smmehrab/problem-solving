# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

from collections import deque

class Solution(object):

    def bfs(self, source, destination, possible_moves):
        queue = deque()
        visited = set()

        current_level = 0
        if self.DEBUG:
            print(str(current_level) + "------------------------------")
        
        queue.append((source, 0))
        visited.add(source)
        while queue:
            board, level = queue.popleft()

            if self.DEBUG:
                if level > current_level:
                    current_level = level
                    print(str(current_level) + "------------------------------")
                if board == destination:
                    print(board+"*")
                else:
                    print(board)

            if board == destination:
                return level

            zero = board.find("0")
            for neighbor in possible_moves[zero]:
                next_board = self.swap(board, zero, neighbor)
                if next_board not in visited:
                    queue.append((next_board, level+1))
                    visited.add(next_board)

        return -1

    def boardToString(self, board):
        result = ""
        for row in board:
            for tile in row:
                result += str(tile)
        return result

    def swap(self, s, i, j):
        s_list = list(s)
        s_list[i], s_list[j] = s_list[j], s_list[i]
        return ''.join(s_list)

    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        self.DEBUG = False

        # source
        row_count = len(board)
        col_count = len(board[0])
        board = self.boardToString(board)
        n = len(board)

        # destination
        solved_board = ""
        for i in range(n-1):
            solved_board += str(i+1)
        solved_board += "0"

        # possible moves
        possible_moves = dict()
        for zero in range(n):
            moves = []
            zero_x = (zero//col_count)
            zero_y = (zero%col_count)
            if zero_x+1 < row_count:
                moves.append(((zero_x+1)*col_count)+zero_y)
            if zero_x-1 >= 0:
                moves.append(((zero_x-1)*col_count)+zero_y)
            if zero_y+1 < col_count:
                moves.append((zero_x*col_count)+zero_y+1)
            if zero_y-1 >= 0:
                moves.append((zero_x*col_count)+zero_y-1)
            possible_moves[zero] = moves

        if self.DEBUG:
            print("source        :  "  + board)
            print("destination   :  "  + solved_board)
            print("possible moves:  ")
            print(possible_moves)
            print("")

        return self.bfs(board, solved_board, possible_moves)
