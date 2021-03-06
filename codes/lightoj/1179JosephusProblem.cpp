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

int solve(int n, int k) {
    return (n==1) ? n : ((solve(n-1, k) + (k-1)) % n) + 1;
}

int main() {
    int testCaseCount, n, k;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> k;
        cout << "Case " << testCase << ": " << solve(n, k) << endl;
    }
    return 0;
}