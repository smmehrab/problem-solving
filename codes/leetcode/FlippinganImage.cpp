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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int> &row : image) {
            int left = -1;
            int right = row.size();
            while( ++left <= --right ) {
                if(row[left] == row[right]) 
                    row[right] = row[left] = 1^row[left];
            }
        }
        return image;
    }
};