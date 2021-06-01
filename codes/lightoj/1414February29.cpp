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
    long long int fromDay, fromYear, toDay, toYear, leapDays;
    char fromMonth[100], toMonth[100];

    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%s %lld, %lld", fromMonth, &fromDay, &fromYear);
        scanf("%s %lld, %lld", toMonth, &toDay, &toYear);

        if (fromMonth[0] != 'F' && !(fromMonth[0] == 'J' && fromMonth[1] == 'a'))
        {
            fromYear++;
        }
        if ((toMonth[0] == 'F' && toDay < 29) || (toMonth[0] == 'J' && toMonth[1] == 'a'))
        {
            toYear--;
        }

        leapDays = ((toYear/4) - ((fromYear-1)/4)) - ((toYear/100) - ((fromYear-1)/100)) + ((toYear/400) - ((fromYear-1)/400));
        printf("Case %d: %lld\n", testCase, leapDays);
    }
    return 0;
}