/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

struct Board {
    int x[8], y[8];
};
typedef struct Board Board;

Board given;
vector<Board> validBoards;

int minimumNumberOfMoves;
int dp[10][1<<9];

// Check if certain y slot is valid for the queenNo queen or not
bool isValid(int queenNo, int x, int y, Board &board) {
    for (int i=0; i<queenNo; i++)
        if (y == board.y[i] || abs(x-board.x[i]) == abs(y-board.y[i]))
            return false;
    return true;
}

// Generating all possible chess board positions
// considering given constraints
void preprocess(int queenNo, Board &board) { 
    if (queenNo == 8)
        validBoards.push_back(board);
    for (int y=0; y<8; y++) {
        if (isValid(queenNo, queenNo, y, board)) {
            board.x[queenNo] = queenNo;
            board.y[queenNo] = y;
            preprocess(queenNo+1, board);
        }
    }
}

// Given the current state of 2 boards & the queenNos of the boards,
// the function returns the number of moves required to change one of 
// the queen's position to the other's
int movesRequired(Board &a, int aQueenNo, Board &b, int bQueenNo) {
    // Coordinates
    int aX = a.x[aQueenNo];
    int aY = a.y[aQueenNo];
    int bX = b.x[bQueenNo];
    int bY = b.y[bQueenNo];

    // Zero Move Away
    if (aX == bX && aY == bY)
        return 0;
    // One Move Away
    else if (aX == bX || aY == bY || abs(aX-bX) == abs(aY-bY))
        return 1;
    // Two Moves Away
    else
        return 2;
}

// Dynamic Programming
int solve(int queenNo, int columnMask, Board validBoard) {
    if (queenNo == 8)
        return 0;
    
    int &ret = dp[queenNo][columnMask];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i=0; i<8; i++) {
        if (!(columnMask & (1<<i)))
            ret = min(ret, movesRequired(validBoard, i, given, queenNo) + solve(queenNo+1, (columnMask | (1<<i)) , validBoard));
    }

    return ret;
}

// Taking Input
void input() {
    string row;
    for (int i=0, queenNo=0; i<8; i++) {
        cin >> row;
        for(int j=0; j<8; j++) {
            if(row[j] == 'q') {
                given.x[queenNo] = i;
                given.y[queenNo++] = j;
            }
        }
    }
}

// Driver
int main() {
    Board board;
    preprocess(0, board);

    int testCaseCount;
    cin >> testCaseCount;
    for (int testCase=1; testCase<=testCaseCount; testCase++) {
        input();

        // Finding out which valid board position provides the minimum number of moves
        // required & what's the minimum number of moves to reach that valid board position
        minimumNumberOfMoves = INF;
        for (Board validBoard : validBoards) {
            memset(dp, -1, sizeof(dp));
            minimumNumberOfMoves = min(minimumNumberOfMoves, solve(0, 0, validBoard));
        }

        cout << "Case " << testCase << ": " << minimumNumberOfMoves << endl;
    }
    return 0;
}