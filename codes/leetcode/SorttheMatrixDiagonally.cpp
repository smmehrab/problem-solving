class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int, vector<int>> diagonals;
        
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                diagonals[i-j].push_back(matrix[i][j]);
            
        for (auto &dmap : diagonals) 
            sort(dmap.second.begin(), dmap.second.end());
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                matrix[i][j] = diagonals[i-j][0];
                diagonals[i-j].erase(diagonals[i-j].begin());
            }
        }
        
        return matrix;
    }
};