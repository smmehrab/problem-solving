#include<stdio.h>
long long pow(long long n,long long m)
{
    long long i,r=1;
    if(m==0) return 1;
    for(i=1;i<=m;i++)
        {r*=n;}
    return r;
}
long long ra(long long n)
{
   long long r[100],x,i,j,y;
    y=0;
    i=0;
    x=n;

    while(n!=0)
    {
        r[i]=(n%10);
        i++;
        n=n/10;
    }

    i--;
    j=0;

    while(j<=i)
    {
        y+=pow(10,(i-j))*r[j];
        j++;
    }

    return (x+y);
}
long long pd(long long n)
{
   long long r[100],i,y;
    i=0;
    while(n!=0)
    {
        r[i]=(n%10);
        i++;
        n=n/10;
    }
    i--;
    for(y=0;y<=(i/2)+1;y++)
    {
        if(r[y]!=r[i-y]) return (-1);
    }
    return (1);
}

int main()
{
 long long a,b,c,d,i,j,t;
    scanf("%lld",&t);
    for(j=0;j<t;j++)
    {
        scanf("%lld",&d);
        b=pd(d);
        c=0;
        while(b!=1)
        {
            d=ra(d);
            b=pd(d);
            c++;
        }

        printf("%lld %lld\n",c,d);

    }
    return 0;
}
