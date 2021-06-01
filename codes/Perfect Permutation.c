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
    int n,r[120]={0},i,j,k;

    scanf("%d",&n);
    if(n%2==1) {printf("-1\n"); return 0;}
    j=n;
    for(i=1;i<=n/2+1;i++)
    {
        if(r[i]==0) r[i]=j;
        if(r[j]==0) r[j]=i;
        if(i==j) {printf("-1\n"); return 0;}
        j--;
    }

    for(i=1;i<=n;i++)
    {
        printf("%d ",r[i]);
    }
    printf("\n");
    return 0;

}
