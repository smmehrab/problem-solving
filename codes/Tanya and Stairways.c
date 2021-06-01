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
    int n,a[2000],steps,stairs[2000],i,j;
    steps=1;
    stairs[2000]= 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=0;
    for(i=1;i<n;i++)
    {
        if(a[i-1]>=a[i])
        {
            stairs[j]=a[i-1];
            j++;
            steps++;
        }
    }
    stairs[j]=a[n-1];
    j++;

    printf("%d\n",steps);

    for(i=0;i<j;i++)
    {
        if(i!=j-1) printf("%d ",stairs[i]);
        else printf("%d\n",stairs[i]);
    }

    return 0;
}
