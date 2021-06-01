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
#include <map>
using namespace std;

int main()
{
    long long int n, distinct = 0;
    unordered_map<string, int> counter;
    cin >> n;
    string x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (counter.find(x[i]) == counter.end()){
            counter[x[i]] = 1;
            distinct++;
        }
    }
    cout << distinct << endl;
    return 0;
}
