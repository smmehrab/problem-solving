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
#include<algorithm>

using namespace std;

long double f(unsigned long long int a){
    long double r=1.00/((a*a)+a);
    return r;
}

int main(){

    unsigned long long int n,l,r,i;
    long double res;

    scanf("%llu",&n);
    while(n--){
        res=0.00;
        scanf("%llu %llu",&l,&r);

        for(i=l;i<=r;i++)
            res+=f(i);

        printf("%0.12Lf\n",res);
    }

    return 0;
}
