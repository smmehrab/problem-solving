class Solution {
private:
    vector<int> row;
    vector<int> col;
    vector<int> subBoards;

    class Cell{
    private:
        int x, y;
    public:
        Cell(int x, int y){
            this->x = x;
            this->y = y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
    };

    bool setBitmap(int r, int c, int bit, bool set_clear) {
        if (set_clear) {
            if ((row[r] & (1 << bit)) || (col[c] & (1 << bit)) || (subBoards[(r/3)*3 + (c/3)] & (1 << bit))) return false;
            row[r] |= 1 << bit;
            col[c] |= 1 << bit;
            subBoards[(r/3)*3 + (c/3)] |= 1 << bit;
        } 
        else {   
            row[r] &= ~(1 << bit);
            col[c] &= ~(1 << bit);
            subBoards[(r/3)*3 + (c/3)] &= ~(1 << bit);
        }

        return true;
    }

    bool solver(vector<vector<char>>& board, int position) {
        int x = position / 9;
        int y = position % 9;
        if (position == 81) return true;
        if (board[x][y] != '.') return solver(board, position+1);

        int mask = row[x] | col[y] | subBoards[(x/3)*3 + (y/3)];
        for (int number=1; number<=9; number++) {
            if (mask & (1<<number)) continue;
            board[x][y] = number + '0';
            setBitmap(x, y, number, true);

            if (solver(board, position+1)) return true;
            setBitmap(x, y, number, false);
        }
        board[x][y] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, 0);
        col.resize(9, 0);
        subBoards.resize(9, 0);

        for (int r = 0; r<9; r++) {
            for (int c = 0; c<9; c++) {
                if (board[r][c] != '.' && !setBitmap(r, c, board[r][c] - '0', true)) return;
            }
        }

        solver(board, 0);
    }
};