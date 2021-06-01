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
    int n,a[1010],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i!=(n-1))
        {
            scanf("%d ",&a[i]);
        }
        else
        {
            scanf("%d",&a[i]);
        }

    }

    for(i=n-1;i>=0;i--)
    {
        if(i!=0)
        {
            printf("%d ",a[i]);
        }
        else
        {
            printf("%d\n",a[i]);
        }

    }

    return 0;
}
