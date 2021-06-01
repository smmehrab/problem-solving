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
    long long int n,m,a,b,p,i,t;
    scanf("%lld %lld",&n,&m);
    a=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t);
        a+=t;
        p=(a/m);
        a%=m;
        printf("%d ",p);
    }
    printf("\n");
    return 0;
}
