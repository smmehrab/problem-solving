class Solution {
private:
    int n, m, number;
    vector<vector<int>> matrix;
    vector<int> position;
    vector<vector<int>> orderOfTraversal;

    void traverse(int i, int j, char d) {
        if(number>(n*m)) return;
        // if(i<0 || j<0 || i>=n ||  j>=m || matrix[i][j]==1) return;
        
        if(matrix[i][j]==0) {
            matrix[i][j] = number;
            orderOfTraversal[number-1].push_back(i);
            orderOfTraversal[number-1].push_back(j);
            number++;
        }
        
        if(d == 'u') traverse(i-1, j, 'u');
        traverse(i, j+1, 'r');
        traverse(i+1, j, 'd');
        traverse(i, j-1, 'l');
        traverse(i-1, j, 'u');
    } 

public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int x, int y) {
        this->n = n;
        this->m = m;
        this->number = 1;
        this->matrix = vector<vector<int>>((n*m), vector<int>(2, 0));
        traverse(x, y, 'r');
        return orderOfTraversal;
    }
};