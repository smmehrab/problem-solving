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
    int n,a[100100]={0},b[100100]={0},i,j,k,r=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t>0)
        {
            a[t]++;
            if(a[t]==1) r++;
        }
        else if(t<0)
        {
            t*=-1;
            b[t]++;
            if(b[t]==1) r++;
        }
    }
    printf("%d\n",r);
    return 0;
}
