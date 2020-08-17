#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
#define PRECISION 0.00000001

int main()
{
    int testCaseCount;
    double l, n, c, el, h, a, low, high, s;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> l >> n >> c;
        if (n == 0)
            cout << "Case " << testCase << ": 0" << endl;
        else
        {
            el = (1 + (n * c)) * l;
            low = 0.00;
            high = l;
            while (high - low > PRECISION)
            {
                h = (low + high) / 2.00;
                a = (l * l) / (4.00 * h);
                s = (a + h) * atan(l / (a - h));

                if (s > el)
                {
                    high = h;
                }
                else
                {
                    low = h;
                }
            }
            cout << "Case " << testCase << ": ";
            cout << fixed << setprecision(6) << h << endl;
        }
    }
    return 0;
}