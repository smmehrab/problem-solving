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

#define MAX 1000000
#define MODULO 1000003
vector<long long int> factorial(MAX+7);

void precalculateFactorials() {
    factorial[0] = factorial[1] = 1;
    for(int i=2; i<=MAX; i++) 
        factorial[i] = ((i%MODULO) * (factorial[i-1]%MODULO)) % MODULO;
}

long long int bigMod(long long int base, int power) {
    if(power==0) return 1;
    else if(power%2==0) {
        long long int r = bigMod(base, power/2);
        return (r*r) % MODULO;
    }
    else return ((base%MODULO) * bigMod(base, power-1)) % MODULO;
}

int main() {
    int testCaseCount;
    long long int n, r, denominator, modularMultiplicativeInverse, nCr;

    precalculateFactorials();
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> r;
        denominator = (factorial[n-r] * factorial[r]) % MODULO;
        modularMultiplicativeInverse = bigMod(denominator, MODULO-2);
        nCr = (factorial[n] * modularMultiplicativeInverse) % MODULO;
        cout << "Case " << testCase << ": " << nCr << endl;
    }

    return 0;
}