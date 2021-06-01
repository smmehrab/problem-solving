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

int main(){
    int testCaseCount;
    double a, b, c, d, s, area;

    scanf("%d",&testCaseCount);
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        s = (b+d+abs(a-c))/2.00;
        area = (a+c) * sqrt(s*(s-b)*(s-d)*(s-abs(a-c)))/abs(a-c);
        printf("Case %d: %lf\n", testCase, area);
    }

    return 0;
}
