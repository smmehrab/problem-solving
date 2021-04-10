class Solution {
private:
    int solve(int i, int j, int previous, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]<=previous) 
            return 0;
        
        int &ret = dp[i][j];
        if(ret==0) {
            int best = solve(i+1, j, matrix[i][j], n, m, matrix, dp);
            best = max(best, solve(i-1, j, matrix[i][j], n, m, matrix, dp));
            best = max(best, solve(i, j+1, matrix[i][j], n, m, matrix, dp));
            best = max(best, solve(i, j-1, matrix[i][j], n, m, matrix, dp));
            ret = 1 + best;
        }
        
        return ret;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int pathLength = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pathLength = max(pathLength, solve(i, j, -1, n, m, matrix, dp));                  
            }
        }       
        
        return pathLength;
    }
};

