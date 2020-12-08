class Solution {
private:
    int n, m;
    vector<vector<int>> matrix;
    vector<int> traversal;

    void traverse(int i, int j, char d) {
        if(i<0 || j<0 || i>=n ||  j>=m || matrix[i][j]==200) return;
                
        traversal.push_back(matrix[i][j]);
        matrix[i][j] = 200;
        
        if(d == 'u') traverse(i-1, j, 'u');
        traverse(i, j+1, 'r');
        traverse(i+1, j, 'd');
        traverse(i, j-1, 'l');
        traverse(i-1, j, 'u');
    } 

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->n = matrix.size();
        this->m = matrix[0].size();
        traverse(0, 0, 'r');
        return traversal;
    }
};