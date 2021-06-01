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
    long long int n,p[100100],q[100100],x,y,s,t,i,a=0;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        if(i==0) scanf("%lld %lld",&x,&y);

        else if(i%2==0)
        {
            scanf("%lld %lld",&x,&y);

            if(x==y)
            {
                x=s;
                y=t;
            }

            else
            {
                p[i-1]=x-s;
                q[i-1]=y-t;
            }
        }

        else
        {
            scanf("%lld %lld",&s,&t);

            if(s==t)
            {
                s=x;
                t=y;
            }

            else
            {
                p[i-1]=s-x;
                q[i-1]=t-y;
            }
        }

        if((p[i-1]<0 && q[i-1]>0)||(p[i-1]>0 && q[i-1]<0)) a=1;
    }

    if(a) printf("Happy Alex\n");
    else printf("Poor Alex\n");
    return 0;
}
