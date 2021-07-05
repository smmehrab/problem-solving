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
    double x, y, z;
};

double findDistance(Point p1, Point p2) {
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y)) + ((p1.z-p2.z)*(p1.z-p2.z)));
}

double solve(Point a, Point b, Point p) {   
    Point mid1, mid2; 
    double distance1, distance2;

    // Ternary Search
    int iterationCount = 100;
    while(iterationCount--) {
        // First Mid Point
        mid1.x = a.x + ((b.x-a.x)/3.0);
        mid1.y = a.y + ((b.y-a.y)/3.0);
        mid1.z = a.z + ((b.z-a.z)/3.0);
        distance1 = findDistance(p, mid1);

        // Second Mid Point
        mid2.x = b.x - ((b.x-a.x)/3.0);
        mid2.y = b.y - ((b.y-a.y)/3.0);
        mid2.z = b.z - ((b.z-a.z)/3.0);
        distance2 = findDistance(p, mid2);
        
        // Comparison
        if(distance1>distance2) 
            a = mid1;
        else 
            b = mid2;    
    }

    return (distance1+distance2)/2.00;
}

int main() {
    cout << setprecision(6) << fixed;
    int testCaseCount;
    Point a, b, p;
    double minDistance;

    cin >> testCaseCount;
    for (int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> p.x >> p.y >> p.z;
        minDistance = solve(a, b, p);
        cout << "Case " << testCase << ": " << minDistance << endl;
    }
    
    return 0;
}