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

int gcd(int a,int b)
{
    if(b==0) {return a;}
    return gcd(b,(a%b));
}

int common_divisors(int a[],int m,int n,int gcd)
{
    int i,j=1;

    for(i=1;i<=gcd;i++)
    {
        if((m%i)==0 && (n%i)==0)
        {
            a[j]=i;
            j++;
        }

    }

    return (j-1);
}


int main()
{
    int t,i;
    int m,n,z,gcdmn;
    int a[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){

    scanf("%d %d",&m,&n);
    gcdmn = gcd(m,n);

    z =common_divisors(a,m,n,gcd);

    printf("%d\n",z);
    }

    return 0;




}
