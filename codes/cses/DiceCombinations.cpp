/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

long long int  n, answer;
long long int modulo = 1e9+7;
long long int dp[1000000];

long long int solve(int sum){
    if(sum >= n) return sum==n;
    
    long long int &ret = dp[sum];
    if(ret!=-1) return ret;
    else ret=0;
    
    for(int option = 1; option <= 6; option++){
        ret = (ret+solve(sum + option))%modulo;
    }

    return ret;
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    answer = solve(0);
    cout << answer << endl;
    return 0;
}