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
	bool operator<(Point point) { 
		return (x<point.x) || (x==point.x && y<point.y); 
	}
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

vector<Point> findConvexHull(vector<Point> &points, int numberOfPoints) { 
	if (numberOfPoints <= 3) 
		return points; 

	int index = 0; 
	vector<Point> convexHull(2*numberOfPoints); 

	// Sort Points Lexicographically 
	sort(points.begin(), points.end()); 

	// Process Lower Hull 
	for (int i=0; i<numberOfPoints; i++) { 
		while (index >= 2 && orientation(convexHull[index-2], convexHull[index-1], points[i]) != Counterclockwise) 
			index--; 
		convexHull[index++] = points[i]; 
	} 

	// Process Upper Hull 
	for (int i = numberOfPoints-1, mid=index+1; i>0; i--) { 
		while (index>=mid && orientation(convexHull[index-2], convexHull[index-1], points[i-1]) != Counterclockwise) 
			index--; 
		convexHull[index++] = points[i-1]; 
	} 

	convexHull.resize(index-1); 
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