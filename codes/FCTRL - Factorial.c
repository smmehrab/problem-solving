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

int zf(long long int n)
{
    long long int z=0;
    while(n)
    {
        n/=5;
        z+=n;
    }
    return z;
}

int main()
{
    long long int t,n,z;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        z=zf(n);
        printf("%lld\n",z);
    }
    return 0;
}
