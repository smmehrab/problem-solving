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
#include<iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int dp[100100];

int findDivisorCount(int a){
    int divCount = 1;
    for(int i=2; i<=a/i; ++i){
        if(a%i == 0){
            int c = 1;
            while(a%i==0){
                a /= i;
                ++c;
            }
            divCount *= c;
        }
    }
    if(a>1)
        divCount *= 2;
    return divCount;
}

int main(){
    int t, cs=0, a, b, x = 1;

    while(x<=100100){
        ++dp[x];
        x += findDivisorCount(x);
    }

    for(int i=1; i<=100100; ++i)
        dp[i] += dp[i-1];

    cin >> t;
    while(t--){
       cin >> a >> b;
       cout << "Case " << ++cs << ": " << dp[b]-dp[a-1] << endl;
    }
    return 0;
}
