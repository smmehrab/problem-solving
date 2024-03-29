/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>
#include <math.h>

int isprime(int i, int rt, int n)
{
    if(n < 2) return 0;
    if(i > rt) return 1;
    if(n%i==0) return 0;
    return isprime(i+1, rt, n);
}

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        if(isprime(2, (int)sqrt(n), n)==1) printf("prime\n");
        else printf("not prime\n");
    }
    return 0;
}
