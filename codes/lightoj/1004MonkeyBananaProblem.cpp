#include <bits/stdc++.h>
using namespace std;

long long int dp[500][500], n, grid[500][500], answer;

long long int solve(int row, int col)
{
    int colCount;
    if(row<n) colCount = row+1;
    else colCount = n - ((row+1)%n);
    if (row >= 0 && row < (2*n)-1 && col >= 0 and col < colCount) 
    {
        long long int &ret = dp[row][col];
        if (ret != -1) return ret;
        if(row+1<n){
            ret = max(ret, solve(row + 1, col) + grid[row][col]);
            ret = max(ret, solve(row + 1, col + 1) + grid[row][col]);
        }
        else{
            ret = max(ret, solve(row + 1, col) + grid[row][col]);
            ret = max(ret, solve(row + 1, col - 1) + grid[row][col]);
        }
        return ret;
    }
    else
        return 0;
}

int main()
{   
    int testCaseCount;
    cin >> testCaseCount;
    for(int testCase = 1; testCase <= testCaseCount; testCase++){
        cin >> n;
        for(int row=0; row< (2*n) - 1; row++){
            int colCount;
            if(row<n) colCount = row+1;
            else colCount = n - ((row+1)%n);
            for(int col=0; col<colCount; col++){
                cin >> grid[row][col];
            }
        }
        memset(dp, -1, sizeof(dp));
        answer = solve(0, 0);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}