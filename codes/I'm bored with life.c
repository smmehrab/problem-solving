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
    long long int a,b,i;
    scanf("%lld %lld",&a,&b);
    if(a>b) a^=b^=a^=b;
    for(i=a-1;i>0;i--) a*=i;
    printf("%lld\n",a);
    return 0;
}
