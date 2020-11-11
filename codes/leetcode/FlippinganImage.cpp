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