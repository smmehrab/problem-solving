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
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include<cstdio>
#include <math.h>
using namespace std;

long long int bigMod(long long int b, long long int p, long long int m){
    if(p==0)
        return 1;
    else if(p&1){
        long long int x = (b%m);
        long long int y = bigMod(b, p-1, m);
        return (x*y)%m;
    }
    else{
        long long int z = bigMod(b, p/2, m);
        return (z*z)%m;
    }
}

int main(){
    long long int b, p, m;
    while(scanf("%lld\n%lld\n%lld", &b, &p, &m) != EOF)
        cout << bigMod(b, p, m) << endl;
    return 0;
}


