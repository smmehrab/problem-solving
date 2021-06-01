/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(10, vector<int>(10, 0));
        vector<vector<int>> columns(10, vector<int>(10, 0));
        vector<vector<int>> subBoards(10, vector<int>(10, 0));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    int number = board[i][j] - '0';
                    if (++rows[i][number] > 1 || ++columns[j][number] > 1 || ++subBoards[(i/3)*3 + (j/3)][number] > 1) return false;
                }
            }
        }
        return true;
    }
};