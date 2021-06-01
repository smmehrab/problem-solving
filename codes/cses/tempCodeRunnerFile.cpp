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

int dp[1010][1010];

int solve(pair<int, int> pos, string grid[]){
    // if (n/10==0) return 1;
    
    // int &ret = dp[n];
    // if (ret!=-1) return ret;
    
    // ret = 1e9;
    // int m = n;
    // while(m){
    //     ret = min(ret, 1+solve(n-(m%10)));
    //     m/=10;
    // }
    
    // return ret;
    return 0;
}
 
int main(){
    int n;
    cin >> n;
    string grid[n];
    for(string &row : grid)
        cin >> row;
    for(string &row : grid)
        cout << row << endl;  
    memset(dp,-1,sizeof (dp));
    cout << solve({0, 0}, grid) << endl;
    return 0;
}