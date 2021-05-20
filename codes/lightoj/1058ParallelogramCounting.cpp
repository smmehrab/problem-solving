#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;

int main() {
    int testCaseCount, n, x, y, numberOfPairs, numberOfParallelograms;
    vector<Point> points;
    vector<Point> midPoints;

	cin >> testCaseCount;
	for(int testCase=1; testCase<=testCaseCount; testCase++) {
		cin >> n;

		points.clear();

		for(int i=0; i<n; i++) {
            cin >> x >> y;
			points.push_back({x, y});
		}

		numberOfPairs = 0;
		for(int i=0; i<n-1; i++) {
			for (int j=i+1; j<n; j++) {
				/*
					Storing (p1.x+p2.x) & (p1.y+p2.y)
					Instead of (p1.x+p2.x)/2 & (p1.y+p2.y)/2
					As the mapping remain unchanged.
				*/
				x = points[i].first + points[j].first;
				y = points[i].second + points[j].second;
				midPoints.push_back({x, y});
                numberOfPairs++;
			}
		}

		sort(midPoints.begin(), midPoints.end());

		numberOfParallelograms = 0, n = 0;
		for(int i=1; i<numberOfPairs; i++) {
			/*
				nC2 parallelogram can be made out of these n pair of points having same mid point.
				nC2 = (n*(n+1))/2
			*/
			if((midPoints[i].first == midPoints[i-1].first) && (midPoints[i].second == midPoints[i-1].second)) 
				n++;
			else 
				numberOfParallelograms += ((n*(n+1))/2), n = 0;
		}

        cout << "Case " << testCase << ": " << numberOfParallelograms << endl;
	}

    return 0;
}