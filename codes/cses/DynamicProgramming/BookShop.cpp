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
    int n, x, option1, option2;

    cin >> n >> x;
    vector<int> costs(n);
    vector<int> pages(n);

    for (int &cost : costs)        
        cin >> cost;
    for(int &page : pages)
        cin >> page;

    /*
        Option1 --> Not Taking Current Book
        Option2 --> Taking Current Book
    */
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0] = 0;
    for(int book=1; book<=n; book++) {
        int cost = costs[book-1];
        int page = pages[book-1];
        for(int money=0; money<=x; money++) {
            option1 = dp[book-1][money];
            option2 = (money>=cost) ? dp[book-1][money-cost] + page : 0;
            dp[book][money] = max(option1, option2);
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}