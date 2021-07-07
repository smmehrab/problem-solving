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
    else return gcd(b,a%b);
}

int lcm(int a,int b) {return ((a*b)/gcd(a,b));}

int main()
{
    int cs=0,g,l,a,b;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) return 0;
        g=gcd(a,b);l=lcm(a,b);
        printf("Case %d:\nGCD: %d\nLCM: %d\n",++cs,g,l);
    }
    return 0;
}
