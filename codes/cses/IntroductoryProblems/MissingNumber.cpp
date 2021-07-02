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
    long long int n, x, total, sum;
    cin >> n;

    total = (n*(n+1))>>1;

    while(--n) {
        cin >> x;
        sum += x;
    } 

    cout << (total-sum) << endl;    
	return 0;
}