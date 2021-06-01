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
    long long int L,v,l,r,t,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&L,&v,&l,&r);
        ans=((l-1)/v)+((L/v)-(r/v));
        printf("%lld\n",ans);
    }
    return 0;
}
