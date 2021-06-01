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
    long long int x, y;
};
typedef struct Point Point;

bool isColinear(Point p1, Point p2, Point p3) {
    long long int x1 = p1.x, y1 = p1.y;
    long long int x2 = p2.x, y2 = p2.y;
    long long int x3 = p3.x, y3 = p3.y;
    return ((y2-y1)*(x3-x2) == (x2-x1)*(y3-y2));
}

int main() {
    int testCaseCount, n;
    
    cin >> testCaseCount;
    for(int testCase=1, maxColinear=1; testCase<=testCaseCount; testCase++, maxColinear=1) {
        cin >> n;
        
        vector<Point> points(n);
        for(Point &point : points)
            cin >> point.x >> point.y;

        if(n>=2)
            maxColinear = 2;
        
        Point p1, p2, p3;
        for(int i=0; i<n-2; i++) {
            p1 = points[i];
            for(int j=i+1, colinear=2; j<n-1; j++, colinear=2) {
    			p2 = points[j];
                for(int k=j+1; k<n; k++) {
                    p3 = points[k];                    
                    if(isColinear(p1, p2, p3))
                        colinear++;
                }
                
                maxColinear = max(maxColinear, colinear);
            }
        }

        cout << "Case " << testCase << ": " << maxColinear << endl;
    }
    
    return 0;
}