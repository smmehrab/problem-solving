/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    
    int n;
    int x1, y1, z1, x2, y2, z2;
    int xLow, yLow, zLow;
    int xHigh, yHigh, zHigh;
    int lowerBound = 0, upperBound = 1010;
    int intersection;

    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;

        xLow = lowerBound;
        yLow = lowerBound;
        zLow = lowerBound;
        xHigh = upperBound;
        yHigh = upperBound;
        zHigh = upperBound;
  
        for(int j=0;j<n;j++){
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >>z2;
  
            xLow = max(xLow, x1);
            yLow = max(yLow, y1);
            zLow = max(zLow, z1);

            xHigh = min(xHigh, x2);
            yHigh = min(yHigh, y2);
            zHigh = min(zHigh, z2);
        }

        intersection = (xHigh-xLow) * (yHigh-yLow) * (zHigh-zLow);
        intersection = (intersection<0) ? 0 : intersection;
        cout << "Case " << testCase << ": " << intersection << endl;
    }

    return 0;
}