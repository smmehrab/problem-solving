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

enum Turn {
    Player1, Player2
};

enum Color {
    Red, Yellow, White
};

enum MoveStatus {
    Invalid, Valid, Winning
};

class Board {
private:
    Color status[6][7];
    int occupancy[7];

    bool isOutOfBound(int column) {
        return (column<0 || column>6);
    }

    bool isAlreadyFull(int column) {
        return occupancy[column]>=6;
    }

    bool isWinningMove(int row, int column, Turn turn) {
        Color playerColor = (turn == Player1) ? Red : Yellow;
        Color color;
        int consecutive;

        // Vertical Check
        consecutive = 0;
        if (occupancy[column]>=4) {
            for(int i=0; i<6; i++) {
                color = status[i][column];
                consecutive = (color == playerColor) ? (consecutive+1) : 0;
                if(consecutive == 4)
                    return true;
            }
        }

        // Horizontal Check
        consecutive = 0;
        for(int j=0; j<7; j++) {
            color = status[row][j];
            consecutive = (color == playerColor) ? (consecutive+1) : 0;
            if(consecutive == 4)
                return true;
        }

        // Diagonal Check (Positive)
        consecutive = 0;
        int offset = min(6-1-row, column);
        for(int i=row+offset, j=column-offset; i>=0 && j<7; i--, j++) {
            color = status[i][j];
            consecutive = (color == playerColor) ? (consecutive+1) : 0;
            if(consecutive == 4)
                return true;
        }

        // Diagonal Check (Negative)
        consecutive = 0;
        offset = min(row, column);
        for(int i=row-offset, j=column-offset; i<6 && j<7; i++, j++) {
            color = status[i][j];
            consecutive = (color == playerColor) ? (consecutive+1) : 0;
            if(consecutive == 4)
                return true;
        }

        return false;
    }

public:
    Board() {
        for(int row=0; row<6; row++) {
            for(int column=0; column<7; column++) {
                this->status[row][column] = White;
            }
        }

        for(int column=0; column<7; column++) {
            this->occupancy[column] = 0;
        }
    }

    int getStatus(int row, int column) {
        return status[row][column];
    }

    MoveStatus makeMove(int column, Turn turn) {
        if (isOutOfBound(column) || isAlreadyFull(column))
            return Invalid;

        int row = 6-1-occupancy[column];
        status[row][column] = (turn == Player1) ? Red : Yellow;
        occupancy[column]++;

        if(isWinningMove(row, column, turn))
            return Winning;

        return Valid;
    }
};

int main() {
    Board board = Board();
    cout << "Welcome to Connect4!" << endl;
    cout << "Enjoy!" << endl;
    cout << endl;

    string player1;
    cout << "Enter Player1's Name: (Red)" << endl;
    cin >> player1;
    cout << endl;

    string player2;
    cout << "Enter Player2's Name: (Yellow)" << endl;
    cin >> player2;
    cout << endl;

    cout << "Game Started..." << endl;
    cout << endl;

    bool gameState = true;
    Turn turn = Player1;
    MoveStatus moveStatus;
    int column;

    while(gameState) {
        cout << "Enter Column Number: (" << ((turn == Player1) ? player1 : player2) << ")" << endl;
        cin >> column;
        cout << endl;

        moveStatus = board.makeMove(column, turn);

        if(moveStatus == Invalid) {
            cout << "Sorry, you made an invalid move. Please, make a valid one." << endl;
            cout << endl;
            continue;
        }
        else if(moveStatus == Winning) {
            cout << "Congratulations, " << ((turn == Player1) ? player1 : player2) << "!" << endl;
            cout << "You've Won!" << endl;
            cout << endl;
            gameState = false;
        }
        else if(moveStatus == Valid) {
            turn = (turn == Player1) ? Player2 : Player1;
        }
    }

    cout << "Well Played! Both Of You!" << endl;
    return 0;
}