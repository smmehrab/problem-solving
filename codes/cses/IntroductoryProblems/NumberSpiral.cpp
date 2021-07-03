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
    long long int t, x, y, number, mx;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        mx = max(x, y);
        number = (mx-1)*(mx-1);
        number += (mx&1) ? (x>y ? y : y+(y-x)) : (y>x ? x : x+(x-y));
        cout << number << endl;
    }
	return 0;
}