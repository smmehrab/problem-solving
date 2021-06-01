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
int max(int n,int m)
{
    if(n>m) return n;
    else return m;
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    a=max((3*a/10),(a-((a/250)*c)));
    b=max((3*b/10),(b-((b/250)*d)));
    if(a>b) puts("Misha");
    else if(a<b) puts("Vasya");
    else puts("Tie");
    return 0;
}
