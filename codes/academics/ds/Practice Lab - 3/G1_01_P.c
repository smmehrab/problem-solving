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
    int t,i,n,j,tmp,max;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        max=0;
        for(j=0;j<n;j++)
        {
            if(j==n-1) scanf("%d",&tmp);
            else scanf("%d ",&tmp);

            if(tmp>max) max = tmp;
        }
        printf("Case %d: %d\n",i+1,max);
    }
    return 0;
}
