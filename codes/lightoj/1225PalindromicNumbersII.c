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

int main()
{
    long long int t,cs=0,n,m,a;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        m=n;
        a=0;
        while(m){
            a*=10;
            a+=(m%10);
            m/=10;
        }
        if(a==n) printf("Case %lld: Yes\n",++cs);
        else printf("Case %lld: No\n",++cs);
    }
    return 0;
}
