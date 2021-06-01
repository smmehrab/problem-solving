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

#define PRECISION 0.00000001

int main() {
    cout << fixed << setprecision(10);

    int testCaseCount;
    double l1, n, C, l2, estimatedL2;
    double h=0;
    double low, high;
    double a, b, c, r, theta;

    cin >> testCaseCount;
    for (int testCase=1; testCase<=testCaseCount; testCase++, h=0) {
        cin >> l1 >> n >> C;
        
        if(n != 0) {
            l2 = (1 + (n*C)) * l1;
            c = l1/2.00;

            low = 0.00;
            high = l1;
            while(high-low > PRECISION) {
                b = (low+high) / 2.00;

                a = (c*c)/(1.00*b);
                r = (a+b)/2.00;
                theta = 2.00 * asin(c/r);
                estimatedL2 = r * theta;

                if(estimatedL2 > l2)
                    high = b;
                else
                    low = b;
            }

            h = b;
        }

        cout << "Case " << testCase << ": " << h << endl;
    }

    return 0;
}