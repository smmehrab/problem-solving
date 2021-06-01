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
    int n,t,s=0,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&t);
            if(i==0||i==(n-1)) s+=t;

            else if((i==((n-1)/2))&&(j==((n-1)/2))) s+=t;

            else if(i==j) s+=t;

            else if(i==n-1-j || n-1-i==j) s+=t;

        }
    }
    printf("%d\n",s);
    return 0;
}
