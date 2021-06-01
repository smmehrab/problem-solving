/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution
{
private:
    bool search(vector<vector<char>> &board, int x, int y, string word, int index)
    {
        if (index == word.size())
            return true;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[x].size() || board[x][y] == '.' || board[x][y] != word[index])
            return false;

        char saved = board[x][y];
        board[x][y] = '.';

        bool match = ( 
            search(board, x + 1, y, word, index + 1) || 
            search(board, x, y + 1, word, index + 1) ||
            search(board, x - 1, y, word, index + 1) || 
            search(board, x, y - 1, word, index + 1)
            );

        board[x][y] = saved;
        return match;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            for (int y = 0; y < board[x].size(); ++y)
            {
                if (board[x][y] == word[0] && search(board, x, y, word, 0))
                    return true;
            }
        }
        return false;
    }
};