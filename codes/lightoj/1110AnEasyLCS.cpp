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

string lcs(string& a, string& b) {
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }


    string subsequence = "";
    int i=n, j=m;
    while(i>0 && j>0) {
        if (a[i-1] == b[j-1]) {
            subsequence += a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(subsequence.begin(), subsequence.end());
    return subsequence;
}

int main() {
    int testCaseCount;
    string a, b, subsequence;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> a >> b;
        subsequence = lcs(a, b);
        // subsequence = (subsequence.size()==0 ? ":(" : subsequence);
        cout << "Case " << testCase << ": " << subsequence << endl;
    }
    return 0;
}