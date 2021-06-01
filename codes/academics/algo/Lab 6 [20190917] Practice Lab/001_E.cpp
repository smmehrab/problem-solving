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
#include<iostream>
using namespace std;

string findAns(string x) {
    int len = x.size();
    if (len%2 == 1)
        return x;

    string u = findAns(x.substr(0, n/2));
    string v = findAns(x.substr(n/2));
    return min(u+v, v+u);
}

int main() {
    string a, b;
    cin >> a >> b;

    if (findAns(a) == findAns(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
