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
    int testCaseCount;
    string url;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        cin >> url;
        int colon = url.find(":");
        string rest = url.substr(colon);
        cout << "Case " << testCase << ": https" << rest << endl;
    }
    return 0;
}