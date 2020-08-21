#include <bits/stdc++.h>
using namespace std;

long long int n, x;
long long int dp[1010];

long long int solve(int moneyLeft, vector <int>& costs, vector <int>& pages){
    if (moneyLeft==0) return 0;
    
    long long int &ret = dp[moneyLeft];
    if (ret!=-1) return ret;
    
    ret = -1;
    for (int i=0; i<n; i++){
        if(costs[i]<=moneyLeft)
            ret = max(ret, pages[i]+solve(moneyLeft-costs[i], costs, pages));
        else break;
    }        
    
    return ret;
}
 
int main(){
    memset(dp,-1,sizeof (dp));
    
    cin >> n >> x;
    vector <int> costs(n);
    for (int &cost : costs)        
        cin >> cost;
    vector <int> pages(n);
    for(int &page : pages)
        cin >> page;

    sort(costs.begin(), costs.end());
    cout << solve(x, costs, pages) << endl;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
        dp[i][j] = dp[i-1][j];
        int left = j-price[i-1];
        if (left >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
        }
        }
    }
    cout << dp[n][x] << endl;

    return 0;
}