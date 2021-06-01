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

int prime(int n)
{
    if(n==3 || n==2) return 1;
    if(n%2==0) return 0;
    int i;

    for(i=3; i<=n/2; i+=2)
    {if(n%i==0) return 0;}

    return 1;
}

int main()
{
    int n,m,i,p,answer=1;

    scanf("%d %d",&n,&m);

    if(prime(m)!=1) answer=0;
    else {for(i=n+1;i<m;i++) {if(prime(i)==1) answer=0; }}

    if(answer==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}
