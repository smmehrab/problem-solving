/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

string a, b, c;

int lcs(int x, int y, int z) {
    int dp[x+1][y+1][z+1];
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=y; j++) {
            for (int k=0; k<=z; k++) {
                if(i == 0 || j == 0 || k==0)
                    dp[i][j][k] = 0;
                else if(a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                else
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
            }
        }
    }
    return dp[x][y][z];
}

int main(){
    int testCaseCount, lenLCS;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> a >> b >> c;
        lenLCS = lcs(a.size(), b.size(), c.size());
        cout << "Case " << testCase << ": " << lenLCS << endl;
    }
    return 0;
}