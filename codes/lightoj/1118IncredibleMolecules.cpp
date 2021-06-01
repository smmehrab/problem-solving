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
#include<math.h>
using namespace std;
 
int main () {
    cout << fixed << setprecision(10);
    int testCaseCount;
    double x1, y1, r1, x2, y2, r2;
    double d;
    double theta1, theta2;
    double sector1, sector2;
    double triangle1, triangle2;
    double overlapped1, overlapped2;
    double overlappedArea;
    
    cin >> testCaseCount;
	for(int testCase=1; testCase<=testCaseCount; testCase++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        d = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    
        // One Circle Inside Another
        if((d+r1<=r2) || (d+r2<=r1))
            overlappedArea = ((r2<r1) ? (r2*r2) : (r1*r1)) * M_PI;
        
        // Just Touched or No Intersection
        else if(d>=r1+r2)
            overlappedArea = 0;
        
        // Intersected
        else {
            theta1 = acos(((r1*r1)+(d*d)-(r2*r2)) / (2.00*r1*d));
            sector1 = 0.5 * r1 * r1 * (2*theta1);
            triangle1 = 0.5 * r1 * r1 * sin(2*theta1);
            overlapped1 = sector1 - triangle1;

            theta2 = acos(((r2*r2)+(d*d)-(r1*r1)) / (2.00*r2*d));
            sector2 = 0.5 * r2 * r2 * (2*theta2);
            triangle2 = 0.5 * r2 * r2 * sin(2*theta2);
            overlapped2 = sector2 - triangle2;    

            overlappedArea = overlapped1 + overlapped2;
        }

        cout << "Case " << testCase << ": " << overlappedArea << endl;
	}

    return 0;
}