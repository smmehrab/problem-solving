class Solution {
private:
    int n;
    vector<vector<string>> solutions;
    vector<string> board;
    vector<int> row;
    vector<int> column;
    vector<int> pDiagonal; // Top to Bottom: Indexing starts from top-left
    vector<int> sDiagonal; // Bottom to Top: Indexing starts from top-right

    bool isSafe(int queenNo, int option) {
        return (row[queenNo]==0 && column[option]==0 && sDiagonal[queenNo+option]==0 && pDiagonal[queenNo-option+n-1]==0);
    }

    void placeQueen(int queenNo, int option) {
        board[queenNo][option] = 'Q';
        row[queenNo] = 1;
        column[option] = 1;
        pDiagonal[queenNo-option+n-1] = 1;
        sDiagonal[queenNo+option] = 1;
    }

    void withdrawQueen(int queenNo, int option) {
        board[queenNo][option] = '.';
        row[queenNo] = 0;
        column[option] = 0;
        pDiagonal[queenNo-option+n-1] = 0; 
        sDiagonal[queenNo+option] = 0;
    }

    void backtrack(int queenNo) {
        if(queenNo==n) {
            solutions.push_back(board);
            return;
        }

        for(int option=0; option<n; option++) {
            if(isSafe(queenNo, option)) {
                placeQueen(queenNo, option);
                backtrack(queenNo+1);
                withdrawQueen(queenNo, option);
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        this->n = n;
        this->board = vector<string>(n, string(n, '.'));
        this->row = vector<int>(n);
        this->column = vector<int>(n);
        this->pDiagonal = vector<int>(2*n-1);
        this->sDiagonal = vector<int>(2*n-1);
        
        backtrack(0);
        return solutions.size();
    }
};