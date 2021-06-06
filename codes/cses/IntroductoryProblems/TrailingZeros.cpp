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

int main() {
    long long int n, t=0;
    cin >> n;
    for(int i=5; i<=n; i*=5) 
        t += (n/i);
    cout << t << endl;
    return 0;
}