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

int main()
{
    int testCaseCount, n, x1, y1, z1, x2, y2, z2, answer;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        }

        printf("Case %d: %d\n", testCase, answer);
    }
    return 0;
}
