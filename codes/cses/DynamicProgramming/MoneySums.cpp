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

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int &value : values)
        cin >> value;
    
    int MAX_SUM = n*1000;
    int sumCount = 0;

    vector<vector<int>> dp(n+1, vector<int>(MAX_SUM+1, -1));
    dp[0][0] = 0;
    for(int coin=1; coin<=n; coin++) {
        int value = values[coin-1];
        for(int sum=0; sum<=MAX_SUM; sum++) {
            int remaining = sum-value;
            dp[coin][sum] = (remaining>=0 && dp[coin-1][remaining]!=-1) ? sum : dp[coin-1][sum];
            if(coin==n && sum>0 && dp[coin][sum]!=-1)
                sumCount++;
        }
    }

    cout << sumCount << endl;
    for(int sum=1; sum<MAX_SUM; sum++) {
        if(dp[n][sum]!=-1)
            cout << dp[n][sum] << " ";
    } 

    return 0;
}