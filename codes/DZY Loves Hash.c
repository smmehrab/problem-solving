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
    long long int p,n,i,j,k,a[100000],d;

    scanf("%lld %lld",&p,&n);

    i=-1;

    for(j=0;j<100000;j++)
    {
        a[j]=-1;
    }

    for(j=0;j<n;j++)
    {
        scanf("%lld",&k);

        d=k%p;

        if(a[d]==-1) a[d]=k;

        else
        {
            if(i==-1) i=j+1;
        }

    }
    printf("%lld\n",i);
    return 0;
}
