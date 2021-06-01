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
    long long int n,t,c,i,r=0,a=0,in;

    scanf("%lld %lld %lld",&n,&t,&c);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&in);
        if(in>t)
        {
            if(a>=c) r+=a-c+1;
            a=0;
        }
        else a++;
    }
    if(a>=c) r+=a-c+1;
    printf("%lld\n",r);
    return 0;

}

