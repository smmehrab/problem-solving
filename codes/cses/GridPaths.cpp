#include <bits/stdc++.h>
using namespace std;

int n;
long long int dp[1010][1010];

long long int solve(pair<int, int> pos, string grid[]){
    int x = pos.first, y = pos.second;
    if (x>=n || y>=n || grid[x][y]=='*') return 0;
    else if(x==n-1 && y==n-1) return 1;
    
    long long int &ret = dp[x][y];
    if (ret!=-1) return ret;
    
    ret = 0;
    (ret += solve({x+1, y}, grid))%=1000000007;
    (ret += solve({x, y+1}, grid))%=1000000007;
    return ret;
}
 
int main(){
    cin >> n;
    string grid[n];
    for(string &row : grid)
        cin >> row;

    memset(dp,-1,sizeof (dp));
    cout << solve({0, 0}, grid) << endl;
    return 0;
}