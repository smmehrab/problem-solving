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
    return 0;
}