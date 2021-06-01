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
    long long int x , y;
};
typedef struct Point Point;

enum Orientation {
    Colinear, Clockwise, Counterclockwise
};

Orientation orientation(Point p, Point q, Point r)  { 
	long long int area = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	if (area == 0) 
        return Colinear;
    return (area>0) ? Clockwise : Counterclockwise;
} 

double distance(Point p1,Point p2) {
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

Point p0;
bool compare(Point p1, Point p2) {
    Orientation orientationStatus = orientation(p0, p1, p2);
    if(orientationStatus==Colinear) 
        return distance(p0, p1) < distance(p0, p2);
    else
        return (orientationStatus==Counterclockwise); 
}

Point nextToTop(stack<Point> &pointStack) {
	Point first = pointStack.top();
	pointStack.pop();
	Point second = pointStack.top();
	pointStack.push(first);
	return second;
}

vector<Point> findConvexHull(vector<Point> &points, int numberOfPoints) {
    vector<Point> convexHull;

    // Finding bottom left most point
    int bottomLeftMost = 0;
    for (int i=1; i<numberOfPoints; i++) 
        if ((points[i].y < points[bottomLeftMost].y) || (points[i].y == points[bottomLeftMost].y && points[i].x < points[bottomLeftMost].x))
            bottomLeftMost = i;
    
    // Bringing that into the start
    swap(points[0], points[bottomLeftMost]);

    // Sorting the points
    p0 = points[0];
    sort(points.begin()+1, points.end(), compare);

    // Modify points vector
    // On polar angle tie, only keep the farthest point
    // Remove the rest of the colinear points
    int validNumberOfPoints = 1; 
    for (int i=1; i<numberOfPoints; i++) {
        while (i<numberOfPoints-1 && orientation(p0, points[i], points[i+1]) == Colinear)
            i++;
        points[validNumberOfPoints++] = points[i];
    }

    if (validNumberOfPoints<3) 
        return convexHull;

    // Core Algorithm
    stack<Point> pointStack;
    pointStack.push(points[0]);
    pointStack.push(points[1]);
    pointStack.push(points[2]);

    for (int i=3; i<validNumberOfPoints; i++) {
        while (pointStack.size()>1 && orientation(nextToTop(pointStack), pointStack.top(), points[i]) != Counterclockwise)
            pointStack.pop();
        pointStack.push(points[i]);
    }

    // Return
    while (!pointStack.empty()) {
        convexHull.push_back(pointStack.top());
        pointStack.pop();
    }

    return convexHull;
}

double angle(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    return acos((b*b-c*c-a*a)/(-2*a*c));
}

int main() {
    cout << setprecision(6) << fixed;

    int testCaseCount, n;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        // Input
        cin >> n;
        vector<Point> points(n);
        for(Point &point : points)
            cin >> point.x  >> point.y;

        // Finding convex hull
        vector<Point> convexHull = findConvexHull(points, n);
        int numberOfConvexHullPoints = convexHull.size();
        
        // Processing answer
        double answer = DBL_MAX;
        if(numberOfConvexHullPoints<3) 
            answer = 0;
        else{
            reverse(convexHull.begin(), convexHull.end());
            int index = 0;
            for(Point point : convexHull) {
                Point next = convexHull[(index+1)%numberOfConvexHullPoints];
                Point previous = convexHull[(index-1+numberOfConvexHullPoints)%numberOfConvexHullPoints];
                answer = min(answer, (angle(point, next, previous)*180)/M_PI);
                index++;
            }
        }

        // Output
        cout << "Case " << testCase << ": " << answer << endl ;
    }
    return 0;
}