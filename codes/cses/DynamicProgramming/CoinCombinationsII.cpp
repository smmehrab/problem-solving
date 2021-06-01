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

int main()
{
    int n, x, p = 1e9 + 7;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int &coin : coins){
        cin >> coin;
        for(int sum = coin; sum<=x; sum++)
            dp[sum] = (dp[sum] + dp[sum-coin])%p;
    }

    cout << dp[x] << endl;
}