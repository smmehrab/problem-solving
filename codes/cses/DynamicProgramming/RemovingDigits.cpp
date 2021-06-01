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

int dp[1000100];

int solve(int n){
    if (n/10==0) return 1;
    
    int &ret = dp[n];
    if (ret!=-1) return ret;
    
    ret = 1e9;
    int m = n;
    while(m){
        ret = min(ret, 1+solve(n-(m%10)));
        m/=10;
    }
    
    return ret;
}
 
int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof (dp));
    cout << solve(n) << endl;
    return 0;
}