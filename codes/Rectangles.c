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
long long int p(long long int a)
{
    long long int i,b=1;
    if(a==0) return 0;
    for(i=1;i<=a;i++) {b*=2;}
    b--;
    return b;
}


int main()
{

    long long int n,m,c,i,j,a[60][60]={0},t,z=0,o=0,r=0;

    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        z=0;o=0;
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0) z++;
            else o++;
        }
        r+=p(z)+p(o);
    }

    for(i=0;i<m;i++)
    {
        z=0;o=0;
        for(j=0;j<n;j++)
        {
            if(a[j][i]==0) z++;
            else o++;
        }
        r+=p(z)+p(o);
    }

    r-=(m*n);

    printf("%lld\n",r);
    return 0;
}
