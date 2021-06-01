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
    int n,h[100000],m[100000],i,j,r;

    scanf("%d",&n);
    j=1; r=1;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&h[i],&m[i]);
        if(i!=0)
        {
            if(h[i-1]!=h[i] || m[i-1]!=m[i])
            {
                if(r<j) r=j;
                j=1;
            }
            else j++;
        }
        if(r<j) r=j;
    }
    printf("%d\n",r);
    return 0;
}
