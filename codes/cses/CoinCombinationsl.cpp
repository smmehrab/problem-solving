#include <bits/stdc++.h>
using namespace std;

long long int n, x;
long long int dp[1000100];

long long int solve(long long int sum, vector <int>& coins){
    if (sum==x) return 1;
    
    long long int &ret = dp[sum];
    if (ret!=-1) return ret;
    
    ret = 0;
    for (long long int i=0; i<n; i++){
        if(sum+coins[i]<=x){
            ret += solve(sum+coins[i], coins);
            if(ret>=1000000007) ret-=1000000007;
        }
        else break;
    }        
    
    return ret;
}
 
int main(){
    memset(dp,-1,sizeof (dp));
    cin >> n >> x;
    vector <int> coins(n);
    for (long long int i=0; i<n; i++)        
        cin >> coins[i];
    sort(coins.begin(), coins.end());
    cout << solve(0, coins) << endl;
    return 0;
}