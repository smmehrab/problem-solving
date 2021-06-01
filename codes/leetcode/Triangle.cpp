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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m;
        for(int row=n-2; row>=0; row--) {
            m = triangle[row].size();
            for(int col=0; col<m; col++) triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        }
        return triangle[0][0];
    }
};