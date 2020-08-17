#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int main()
{
    long long int n,a[200000],b[200000],i,j,k,m,r,ans,amin,bmin,min,x,y,z;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
    }

    x=a[0];
    for(i=0;i<n;i++)
    {

    }



}
