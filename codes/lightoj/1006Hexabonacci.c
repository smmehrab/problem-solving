/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
int main() {
    long long int i,n, caseno = 0, cases, fn[100000],a, b, c, d, e, f;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        fn[0]=a; fn[1]=b; fn[2]=c; fn[3]=d; fn[4]=e; fn[5]=f;
        for(i=6;i<=n;i++) fn[i]=(fn[i-1]+fn[i-2]+fn[i-3]+fn[i-4]+fn[i-5]+fn[i-6])% 10000007;
        printf("Case %lld: %lld\n", ++caseno, fn[n]% 10000007);
    }
    return 0;
}
