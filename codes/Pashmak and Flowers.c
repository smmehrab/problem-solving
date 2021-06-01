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
#include<stdlib.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(long long int*)a - *(long long int*)b );
}


int main()
{
    long long int n,b[200100],m,c,i,t,l,r,md=0;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
    }

	qsort(b, n, sizeof(long long int), cmpfunc);
    m=b[n-1]-b[0];

	l=1;
	r=1;
    for(i=1;i<n;i++)
    {
        if(b[0]==b[i]) l++;
    }

    for(i=n-2;i>=0;i--)
    {
        if(b[n-1]==b[i]) r++;
    }
    if(r==n || l==n) c=n*(n-1)/2;
    else c=r*l;
    printf("%lld %lld\n",m,c);

	return 0;
}
