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

struct Point {
    double x, y;
};

double findDistance(Point p1, Point p2) {
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y)));
}

double solve(Point a, Point b, Point c, Point d) {   
    Point abMid1, abMid2, cdMid1, cdMid2; 
    double distance1, distance2;

    // Ternary Search
    int iterationCount = 100;
    while(iterationCount--) {
        // First Mid Points
        abMid1.x = a.x + ((b.x-a.x)/3.0);
        abMid1.y = a.y + ((b.y-a.y)/3.0);
        cdMid1.x = c.x + ((d.x-c.x)/3.0);
        cdMid1.y = c.y + ((d.y-c.y)/3.0);
        distance1 = findDistance(abMid1, cdMid1);

        // Second Mid Points
        abMid2.x = b.x - ((b.x-a.x)/3.0);
        abMid2.y = b.y - ((b.y-a.y)/3.0);
        cdMid2.x = d.x - ((d.x-c.x)/3.0);
        cdMid2.y = d.y - ((d.y-c.y)/3.0);
        distance2 = findDistance(abMid2, cdMid2);
        
        // Comparison
        if(distance1>distance2) 
            a = abMid1, c = cdMid1;
        else 
            b = abMid2, d = cdMid2;    
    }

    return (distance1+distance2)/2.00;
}

int main() {
    cout << setprecision(6) << fixed;
    int testCaseCount;
    Point a, b, c, d;
    double minDistance;

    cin >> testCaseCount;
    for (int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        minDistance = solve(a, b, c, d);
        cout << "Case " << testCase << ": " << minDistance << endl;
    }
    
    return 0;
}