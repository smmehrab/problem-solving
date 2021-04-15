class Solution {
private:
    void multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int x = (a[0][0]*b[0][0]) + (a[0][1]*b[1][0]);
        int y = (a[0][0]*b[0][1]) + (a[0][1]*b[1][1]);
        int z = (a[1][0]*b[0][0]) + (a[1][1]*b[1][0]);
        int w = (a[1][0]*b[0][1]) + (a[1][1]*b[1][1]);
        a[0][0] = x, a[0][1] = y, a[1][0] = z, a[1][1] = w;
    }
    
    void power(vector<vector<int>>& matrix, int n) {
        if (n>1) {
            power(matrix, n/2);
            multiply(matrix, matrix);

            vector<vector<int>> temp {
                {1, 1},
                {1, 0}
            };
                         
            if (n&1)
                multiply(matrix, temp);
        }
    }
    
public:
    int fib(int n) {
        if(n<=1)
            return n;
        
        vector<vector<int>> matrix {
            {1, 1},
            {1, 0}
        };
             
        power(matrix, n-1);
        return matrix[0][0];
    }
};