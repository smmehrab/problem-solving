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
    int n,a[100100]={0},i,j,k=0;
    char t;
    scanf("%d",&n);
    if(n==1) k=1;
    i=0;
    while(i<=n)
    {
        scanf("%c",&t);
        j=t-'a';
        a[j]++;
        if(a[j]>1) k=1;
        i++;
    }
    if(k==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
