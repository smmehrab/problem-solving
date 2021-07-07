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
    int n,i,j,m[100][100];
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j) printf("1");
            else printf("0");
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

