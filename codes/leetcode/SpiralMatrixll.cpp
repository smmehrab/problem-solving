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
private:
    int n, number;
    vector<vector<int>> matrix;
    void traverse(int i, int j, char d) {
        if(i<0 || j<0 || i>=n ||  j>=n || matrix[i][j]>0) return;
                
        matrix[i][j] = number++;
        
        if(d == 'u') traverse(i-1, j, 'u');
        traverse(i, j+1, 'r');
        traverse(i+1, j, 'd');
        traverse(i, j-1, 'l');
        traverse(i-1, j, 'u');
    } 

public:
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        this->number = 1;
        this->matrix = vector<vector<int>>(n, vector<int>(n, 0));
        traverse(0, 0, 'r');
        return matrix;
    }
};