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

long long int modulo = 1e9+7;

int main()
{
    int n;
    long long int answer, nFact=1, TpN=1;
    cin >> n;
    for(int i=1; i<=n; i++){
        nFact = (nFact*i) % modulo;
        if(i<=n-1) TpN = (TpN*2) % modulo;
    }
    cout << nFact << " " << TpN << endl;
    cout << nFact-TpN << endl;
    answer = (nFact + modulo - TpN) % modulo;
    cout << answer << endl;
    return 0;
}