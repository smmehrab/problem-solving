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
	int x, y; 
}; 
typedef struct Point Point;

enum Orientation {
    Colinear, Clockwise, Counterclockwise
};

Orientation orientation(Point p, Point q, Point r)  { 
	int area = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	if (area == 0) return Colinear;
	return (area>0) ? Clockwise: Counterclockwise;
} 

vector<Point> findConvexHull(vector<Point>& points, int numberOfPoints) { 
	vector<Point> convexHull; 

	if (numberOfPoints < 3) 
        return convexHull; 

	int leftMost = 0; 
	for (int i=1; i<numberOfPoints; i++) 
			leftMost = (points[i].x < points[leftMost].x) ? i : leftMost; 

	int p = leftMost, q; 
	do { 
		convexHull.push_back(points[p]); 
		q = (p+1)%numberOfPoints; 
		for (int i=0; i<numberOfPoints; i++) { 
		    if (orientation(points[p], points[i], points[q]) == Counterclockwise) 
			    q = i; 
		} 

		p = q; 
	} while (p != leftMost);

    return convexHull;
} 

int main() { 
    int numberOfPoints;
    cout << "Enter Number of Points:" << endl;
    cin >> numberOfPoints;

    vector<Point> points(numberOfPoints);
    cout << "Enter " << numberOfPoints << " Points Respectively: (x, y, space separated)" << endl;
    for(Point &point : points)
        cin >> point.x >> point.y;

    cout << "Convex Hull of the Given Points:" << endl;
	vector<Point> convexHull =  findConvexHull(points, numberOfPoints); 
	for (Point point : convexHull) 
		cout << point.x << " "<< point.y << endl; 
	return 0; 
} 