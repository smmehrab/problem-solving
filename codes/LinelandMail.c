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
    while(1){
    int n,i,a[100100];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("%d ",(a[i+1]-a[i]));
        }
        else if(i==n-1)
        {
            printf("%d ",(a[i]-a[i-1]));
        }
        else if((a[i+1]-a[i])>=(a[i]-a[i-1]) && i!=0 && i!=n-1)
        {
            printf("%d ",(a[i]-a[i-1]));
        }
        else if((a[i+1]-a[i])<(a[i]-a[i-1]) && i!=0 && i!=n-1)
        {
            printf("%d ",(a[i+1]-a[i]));
        }


        if((a[i]-a[0])>=(a[n-1]-a[i]))
        {
            printf("%d\n",(a[i]-a[0]));
        }
        else
        {
            printf("%d\n",(a[n-1]-a[i]));
        }
    }
    }
    return 0;
}
