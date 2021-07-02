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

void solve(long long int n) {
    cout << n << " ";
    if(n>1) {
        n = (n&1) ? ((3*n)+1) : (n>>1);
        solve(n);
    }
}

int main() {
    long long int n;
    cin >> n;
    solve(n);
	return 0;
}