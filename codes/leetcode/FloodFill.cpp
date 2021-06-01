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
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        if (image[x][y] == color) {
            image[x][y] = newColor;
            if (x >= 1) dfs(image, x-1, y, color, newColor);
            if (y >= 1) dfs(image, x, y-1, color, newColor);
            if (x+1 < image.size()) dfs(image, x+1, y, color, newColor);
            if (y+1 < image[0].size()) dfs(image, x, y+1, color, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        if (image[x][y] != newColor) dfs(image, x, y, image[x][y], newColor);
        return image;
    }
};