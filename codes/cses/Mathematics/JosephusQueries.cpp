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

int answer;

int solve(int i, int n, int k) {
    return (n==1) ? 1 : ((solve(i+1, n-1, k) + 1) % n) + 1;
}

int main() {
    int q, n, k;
    cin >> q;
    while(q--) {
        cin >> n >> k;
        int j = solve(0, n, k);
        cout << answer << endl;
    }
    return 0;
}