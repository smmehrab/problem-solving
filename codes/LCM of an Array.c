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

typedef long long int ll;

int gcd(int a, int b)
{if (b == 0) return a;
return gcd(b, a % b);}

ll lcm(int arr[], int n)
{
    ll ans = arr[0],i;
    for (i = 1; i < n; i++) ans = (((arr[i] * ans)) /(gcd(arr[i], ans)));
    return ans;
}

int main()
{
    int a[100000],n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    printf("%lld", lcm(a,n));
    return 0;
}

