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
    unsigned long long int n,m,k,t,s;
    scanf("%llu",&t);
    for(k=0;k<t;k++)
    {
        scanf("%llu %llu",&n,&m);
        s=n*m/2;
        printf("Case %llu: %llu\n",k+1,s);
    }
    return 0;

}
