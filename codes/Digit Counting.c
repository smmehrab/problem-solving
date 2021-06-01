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
    int t,n,a[100000]={0},i,j,k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            a[i]=0;
        }
        i=1;
        while(i<=n)
        {
            k=i;

            if(k>=1000) {a[i/1000]++; i%=1000;}

            if(k>=100) a[i/100]++;  i%=100;

            if(k>=10) a[i/10]++;

            a[i%10]++;

            i++;
        }
        i=0;
        while(i<=9)
        {
            if(i!=9) printf("%d ",a[i]);
            else printf("%d\n",a[i]);
            i++;
        }
    }
    return 0;
}
