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
    int t,n,enter,exit,in,i,j,k,max;
    scanf("%d",&t);
    while(t--)
    {
        int a[100000]={0};
        k=0;
        max=0;

        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&enter,&exit);
            if(exit>k) k=exit;
            for(i=enter;i<exit;i++) a[i]++;
        }

        for(i=0;i<=k;i++) if(a[i]>max) max=a[i];
        printf("%d\n",max);
    }
    return 0;
}
