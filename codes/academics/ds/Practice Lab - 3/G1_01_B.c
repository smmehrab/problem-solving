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

void expand(long long int n)
{
    if(n>=10000000)
    {
        expand(n/10000000);
        n=n%10000000;
        printf(" kuti");
    }

    if(n>=100000)
    {
        expand(n/100000);
        n=n%100000;
        printf(" lakh");
    }

    if(n>=1000)
    {
        expand(n/1000);
        n=n%1000;
        printf(" hajar");
    }

    if(n>=100)
    {
        expand(n/100);
        n=n%100;
        printf(" shata");
    }

    if(n!=0)
    {printf(" %lld",n);}
}

int main()
{
    long long int n,t=0;
    while(scanf("%lld",&n)==1)
    {
        t++;
        printf("%4lld.",t);

        if(n==0) printf(" 0");

        expand(n);

        printf("\n");
    }
    return 0;
}
