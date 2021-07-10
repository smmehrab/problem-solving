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
    int removal = (n==1) ? 1 : ((solve(n-1, k) + (k-1)) % n) + 1;
    cout << removal << " ";
    return removal;
}

int main() {
    int n;
    cin >> n;
    n = solve(n, 2);
    return 0;
}