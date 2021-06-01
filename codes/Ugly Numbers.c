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

long long int min(long long int m,long long int n,long long int o)
{
    if(m<=n && m<=o) return m;
    else if(n<=m && n<=o) return n;
    else return o;
}

long long int nth_ugly(long long int n)
{
    long long int i,ugly[n],i2=0,i3=0,i5=0,next_m2=2,next_m3=3,next_m5=5,next_ugly=1;

    ugly[0]=1;
    for(i=1;i<n;i++)
    {
       next_ugly= min(next_m2,next_m3,next_m5);
       ugly[i]=next_ugly;

       if (next_ugly==next_m2)
       {i2++; next_m2=ugly[i2]*2;}

       if(next_ugly==next_m3)
       {i3++; next_m3=ugly[i3]*3;}

       if(next_ugly==next_m5)
       {i5++; next_m5=ugly[i5]*5;}

    }
    return next_ugly;
}

int main()
{
    long long int n = 10;
    printf("The 1500'th ugly number is %lld.\n",nth_ugly(n));
    return 0;
}
