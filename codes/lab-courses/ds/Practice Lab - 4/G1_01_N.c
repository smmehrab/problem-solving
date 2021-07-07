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
    long long int m,n,k,l[10000],r[10000],x[10000],i,j,p,g;
    char cmp,tmp;
    scanf("%lld",&m);
    while(m--)
    {
        n=0;k=0;
        scanf("%lld %lld",&n,&k);
         for(i=0;i<n;i++)
        {
            x[i]=0;
            l[i]=0;
            r[i]=0;
        }
        g=0;j=0;i=0;



        while(k--)
        {
            p=0;
            scanf("%lld",&p);

            i=0;
            while(i<p)
            {

                scanf("%lld",&l[i]);
                i++;
            }

            i=0;
            while(i<p)
            {
                scanf("%lld",&r[i]);
                i++;
            }

            scanf(" %c",&cmp);

            if(cmp == '=')
            {
                for(i=0;i<p;i++)
                {
                    x[l[i]]=l[i];
                    x[r[i]]=r[i];
                }
            }
            else
            {
                for(i=0;i<p;i++)
                {
                    if(x[l[i]]!=l[i]) x[l[i]]=-1;
                    if(x[r[i]]!=r[i]) x[r[i]]=-1;
                }
            }

        }

        j=0;g=0;
        for(i=0;i<n;i++)
        {
            if(x[i]==-1)
            {
                j++;
                g=i;
                if(j>1)
                {
                    g=0;
                    break;
                }
            }
        }
        printf("%lld\n",g);
    }
    return 0;
}

