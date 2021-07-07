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

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int x=gcd(a,b);
    printf("%d\n",x);
    return 0;
}
