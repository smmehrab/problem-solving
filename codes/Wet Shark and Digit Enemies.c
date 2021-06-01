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

long long int po(long long int n,long long int p)
{
    long long int r=1;
    while(p--)
    {
        r*=n;
    }
    return r;
}

long long int squareDigitsSum(long long int n)
{
    long long int r=0,i;
    while(n)
    {
        i=(n%10);
        r+=i*i;
        n/=10;
    }
    return r;
}

long long int getPower(long long int n)
{
    return (n-squareDigitsSum(n));
}

int main()
{
    long long int n,maxN,maxP,minN,minP;
    scanf("%lld",&n);

    if(n>2) minN=po(10,n-1)+9;
    else minN= po(10,n)-1;

    minP=getPower(minN);

    if(n>2) maxN=po(10,n) - 50;
    else maxN=po(10,n-1);

    maxP=getPower(maxN);

    printf("%lld\n%lld\n%lld\n%lld\n",maxN,minN,maxP,minP);
    return 0;
}
