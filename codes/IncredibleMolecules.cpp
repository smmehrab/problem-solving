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
    int testCaseCount, x1, y1, r1, x2, y2, r2;
    double commonArea, distanceBetweenCs, sumOfRadius, commonRadius, commonHeight, h1, h2, theta, s1, s2;

    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        distanceBetweenCs = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
        sumOfRadius = r1 + r2;

        if(sumOfRadius<distanceBetweenCs)
            commonArea = 0.00;
        else{
            commonRadius = sumOfRadius - distanceBetweenCs;
            h1 = r1 - (commonRadius/2.00);
            h2 = r2 - (commonRadius/2.00);
        }

        cout << "Case " << testCase << ": " << commonArea << endl;
    }
    return 0;
}
