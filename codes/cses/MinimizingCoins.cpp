#include <bits/stdc++.h>
using namespace std;

long long int  n, x, answer;
int coins[1000010], coin;
long long int dp[1000010];

long long int solve(int sum){
    if(sum == 0) return 0;
    
    long long int &ret = dp[sum];
    if(ret!=-1) return ret;
    else ret=1e9;
    
    for(int i=0; i<n; i++) {
        coin = coins[i];
        if(sum>=coin){
            ret = min(ret, 1+solve(sum - coin));
        }
    }
    
    return ret;
}

int main()
{
    cin >> n >> x;
    for(int &coin : coins) cin >> coin;
    memset(dp, -1, sizeof(dp));
    answer = solve(x);
    if(answer >= 1e9) answer = -1;
    cout << answer << endl;
    return 0;
}