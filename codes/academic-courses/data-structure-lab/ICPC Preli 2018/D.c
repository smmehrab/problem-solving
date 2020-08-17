#include<stdio.h>

long long int ifprime(long long int n)
{
    long long int i=2,c=1;

    if(n<2) c=0;
    if(n%2==0 || n%3==0) c=0;

    else
    {
        for(i=5; i<=(n/2); i+=6)
        {
            if(n%i==0 || n%(i+2)==0)
            {
                c=0;
                break;
            }
        }
    }

    return c;
}

int numOfDigits(long long int n)
{
    int c=0;
    while(n)
    {
        n/=10;
        c++;
    }
    return c;
}

int main()
{
    long long int t,cs=0,n,i,j,k,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        d=numOfDigits(n);

    }
}

