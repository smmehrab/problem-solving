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
    int n,i,j,a[2000]={0},avg=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        avg+=a[i];
    }
    avg=(2*avg)/n;

    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=i+1;j--)
        {
            if((a[i]+a[j])==avg)
            {
                a[i]=-1; a[j]=-1;
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}
