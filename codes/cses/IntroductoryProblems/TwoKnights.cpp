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
    long long int n, numberOfWays;
    cin >> n;
    for(long long int k=1; k<=n; k++) {
        numberOfWays = (((k*k) * ((k*k)-1))/2) - (2 * (2 * ((k-1)*(k-2))));
        cout << numberOfWays << endl;
    }
	return 0;
}