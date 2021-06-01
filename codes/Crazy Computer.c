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
    long long int n,c,i,w=1,k,t;
    scanf("%lld %lld",&n,&c);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t);
        if(i==0) k=t;
        else
        {
            k=t-k;
            if(c>=k) w++;
            else w=1;
            k=t;
        }
    }
    printf("%lld\n",w);
    return 0;
}
