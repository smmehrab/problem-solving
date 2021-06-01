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

#define PRECISION 0.000000001

double calculateHeight(double x, double y, double r)
{
    double a = sqrt((x*x) - (r*r));
    double b = sqrt((y*y) - (r*r));
    return ((a*b)/(a+b));
}

double binarySearch(double x, double y, double c){
    double low = 0.00;
    double high = min(x, y);
    double mid, height;

    while(high-low > PRECISION){
        mid=(low+high)/2.00;
        height = calculateHeight(x, y, mid);

        if(height==c){
            break;
        }
        else if(height>c){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    int testCaseCount;
    double x,y,c,r;

    scanf("%d",&testCaseCount);
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        scanf("%lf %lf %lf", &x, &y, &c);
        r = binarySearch(x, y, c);
        printf("Case %d: %lf\n", testCase, r);
    }

    return 0;
}
