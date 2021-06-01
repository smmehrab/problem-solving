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
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

// Driver Code
int main()
{
    int testCaseCount;
    int testCase;
    long long int p, l, divisorLimit;

    scanf("%d", &testCaseCount);

    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%lld %lld", &p, &l);

        p -= l;
        divisorLimit = sqrt(p+1);
        set<long long int> answer;

        printf("Case %d:", testCase);

        if (p < l)
        {
            printf(" impossible\n");
            continue;
        }

        for (int divisor = 1; divisor <= divisorLimit; ++divisor)
        {
            if (p % divisor == 0)
            {
                if (divisor > l)
                {
                    answer.insert(divisor);
                }
                if ((p / divisor) > l)
                {
                    answer.insert(p / divisor);
                }
            }
        }

        if(answer.size()==0){
            printf(" impossible\n");
            continue;
        }

        set<long long int>::iterator iterator;
        for (iterator = answer.begin(); iterator != answer.end(); ++iterator)
        {
            cout << ' ' << *iterator;
        }
        printf("\n");
    }
    return 0;
}