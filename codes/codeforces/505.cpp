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
    int n, m, answer, indexStatus, xorOfTheUpper2by1Col, xorOfTheLower2by1Col, maskX, maskY;
                
    cin >> n >> m;
    int a[n][m];
    char x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            a[i][j] = x -'0';
        }
    }

    if (n >= 4)
        answer = -1;
    else if (n == 1)
        answer = 0;
    else
    {
        if (n == 2)
        {
            int requiredChanges[2] = {0};
            for (int i = 0; i < m; ++i)
            {
                indexStatus = i & 1; // Even/Odd Index

                xorOfTheUpper2by1Col = a[0][i] ^ a[1][i];
                maskX = xorOfTheUpper2by1Col ^ indexStatus;

                ++requiredChanges[maskX];
            }
            answer = min(requiredChanges[0], requiredChanges[1]);
        }
        else
        {
            int requiredChanges[2][2] = {{m, m}, {m, m}};
            for (int i = 0; i < m; ++i)
            {
                indexStatus = i & 1; // Even/Odd Index

                xorOfTheUpper2by1Col = a[0][i] ^ a[1][i];
                maskX = xorOfTheUpper2by1Col ^ indexStatus;

                xorOfTheLower2by1Col = a[1][i] ^ a[2][i];
                maskY = xorOfTheLower2by1Col ^ indexStatus;

                --requiredChanges[maskX][maskY];
            }
            answer = min({requiredChanges[0][0], requiredChanges[0][1], requiredChanges[1][0], requiredChanges[1][1]});
        }
    }

    cout << answer << endl;
    return 0;
}