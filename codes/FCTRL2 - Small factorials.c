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
#include<string.h>

#define MAX 500

long long int multiply(long long int x,long long int res[],long long int res_size)
{
    long long int carry = 0,i,product;

    for (i=0; i<res_size; i++)
    {
        product = res[i] * x + carry;
        res[i] = product % 10;
        carry  = product/10;
    }

    while (carry)
    {
        res[res_size++] = carry%10;
        carry/=10;
    }

    return res_size;
}

void factorial(long long int n)
{
    long long int res[MAX],res_size,x,i;

    res[0] = 1;
    res_size = 1;

    for (x=2; x<=n; x++) res_size = multiply(x, res, res_size);
    for (i=res_size-1; i>=0; i--) printf("%d",res[i]);
}

int main()
{
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        factorial(n);
        printf("\n");
    }
    return 0;
}
