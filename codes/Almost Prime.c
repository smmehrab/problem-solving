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
#include<math.h>
int ifprime(int n)
{
    int i=2,c=1;
    if(n%i==0)
    {
        c=0;
    }
    else
    {
        for(i=3; i<=n/2; i+=2)
        {
            if(n%i==0)
            {
                c=0;
                break;
            }
        }
    }

    return c;
}


int main()
{
    int n,i,j,k,c,m;
    scanf("%d",&n);
    m=0;

    for(i=6;i<=n;i++)
    {
        c=0;
        j=2;
        k=i;
        if(ifprime(k)==1) continue;
        if(k%j==0)
        {
            c++;
            while(k%j==0)
            {k=k/j;}
        }

        for(j=3;j<=k;j+=2)
        {
            if(k%j==0)
            {
                c++;
                while(k%j==0)
                {k=k/j;}
            }
        }

        if(c==2)
        {
            m++;
        }
    }
    printf("%d\n",m);
    return 0;
}

