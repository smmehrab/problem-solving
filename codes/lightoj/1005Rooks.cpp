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

int main ()
{
    unsigned long long int testCaseCount, n, k, totalWays;
    scanf("%llu",&testCaseCount);

    for(unsigned long long int testCase = 1; testCase<=testCaseCount; testCase++){
        scanf("%llu %llu",&n,&k);
        totalWays=1;
        for (unsigned long long int rook=1; rook<=k; rook++){
            totalWays *= (n*n);
            totalWays /= rook;
            n--;
        }
        printf("Case %llu: %llu\n", testCase, totalWays);
    }

    return 0;
}