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
#include<math.h>

int isprime(int i, int rt, int n)
{
    if(n < 2) return 0;
    if(i > rt) return 1;
    if(n%i==0) return 0;
    return isprime(i+1, rt, n);
}

int main()
{
    unsigned long long int n,i=0,j,s;
    scanf("%llu",&n);
        while(i<n)
        {
            scanf("%llu",&j);
            s=sqrt(j);
            if((s*s)!=j || s==1) printf("NO\n");
            else if(isprime(2,(int)sqrt(s),s)) printf("YES\n");
            else printf("NO\n");
            i++;
        }
    return 0;
}
