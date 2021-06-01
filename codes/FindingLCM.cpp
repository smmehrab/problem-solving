/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int testCaseCount;
    long long int a, b, c, lcm, lcmAb;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d %lld", &a, &b, &lcm);
        lcmAb = (a*b)/gcd(a, b);
        lcm = (lcmAb*c)/gcd(lcmAb, c);
        
        printf("Case %d: %lld\n", testCase, c);

    }
    return 0;
}
