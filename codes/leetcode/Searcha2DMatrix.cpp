class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;

        int n = matrix.size(), m = matrix[0].size(), row;
        for(row=0; row<n-1; row++)
            if(matrix[row][0]<=target && matrix[row][m-1]>=target)
                break;
        
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};