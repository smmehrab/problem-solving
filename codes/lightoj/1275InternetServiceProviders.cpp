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
    long long int testCaseCount, n, c, t, p1, p2;
    cin >> testCaseCount;
    for (long long int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n >> c;
        if (n == 0)
            t = 0;
        else
        {
            t = (c / (2 * n));

            p1 = t * (c - (t * n));
            p2 = (t + 1) * (c - ((t + 1) * n));

            if (p2 > p1)
                t++;
        }
        cout << "Case " << testCase << ": " << t << endl;
    }
    return 0;
}
