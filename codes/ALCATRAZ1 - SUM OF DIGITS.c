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
#include<string.h>

int main()
{
    long long int t,s,l;
    char n[100000];
    scanf("%lld",&t);
    while(t--)
    {
        s=0;
        scanf("%s", n);
        l=strlen(n);
        while(l--) s+=(int)(n[l]-'0');
        printf("%lld\n",s);
    }
    return 0;
}
