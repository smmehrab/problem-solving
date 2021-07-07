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
    int t,n,i,j,k,l,maj=0,min=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&t);
            if(i==j) maj+=t;
            if(i==n-1-j) min+=t;
        }
    }
    printf("Major Diagonal Sum: %d\nMinor Diagonal Sum: %d\n",maj,min);
    return 0;
}
