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
    long long int x,a[200100],b[200100]={0},c[200100]={0},i,j=-1,n,t;

    scanf("%lld %lld",&n,&x);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

        b[a[i]]++;

        if(b[a[i]]>1) j=0;
    }

    if(j!=0)
    {
            for(i=0;i<n;i++)
            {
                t=a[i]&x;
                if(t!=a[i])
                {   c[t]++;
                    if(b[t]==1)
                    {j=1; break;}
                }
            }
    }

    if(j==-1)
    {
        for(i=0;i<n;i++)
        {
            t=a[i]&x;
            if(t!=a[i])
            {
                if(c[t]>1)
                {j=2; break;}
            }
        }
    }

    printf("%lld\n",j);

    return 0;
}
