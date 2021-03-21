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

int distanceSquare(Point p1, Point p2) {
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

Point p0;
bool compare(const Point &p1, const Point &p2) {
    int orientationStatus = orientation(p0, p1, p2);
    if (orientationStatus == Colinear)
        return (distanceSquare(p0, p1) < distanceSquare(p0, p2));
    return (orientationStatus == Counterclockwise);
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

// Driver program to test above functions
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