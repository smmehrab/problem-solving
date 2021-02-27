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