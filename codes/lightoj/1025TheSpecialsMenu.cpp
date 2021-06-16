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

long long int solve(int left, int right, string word, vector<vector<long long int>>& dp) {
    if(left>right)
        return 0;
    
    if(left == right)
        return 1;

    if(dp[left][right] == -1) {
        if(word[left] == word[right])
            dp[left][right] = 1 + solve(left+1, right, word, dp) + solve(left, right-1, word, dp);
        else 
            dp[left][right] = solve(left+1, right, word, dp) + solve(left, right-1, word, dp) - solve(left+1, right-1, word, dp);
    }

    return dp[left][right];
}

int main() {
    int testCaseCount, n;
    long long int allPossiblePalindromes;
    string word;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> word;
        n = word.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        allPossiblePalindromes = solve(0, n-1, word, dp);
        cout << "Case " << testCase << ": " << allPossiblePalindromes << endl;
    }
    return 0;
}