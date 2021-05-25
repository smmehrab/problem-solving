#include <bits/stdc++.h>
using namespace std;

int redirect(int n, vector<int> cities[], map<pair<int,int>, int> roads, string direction) {
    int cost = 0;
    int current = 1;
    int next = (direction == "clockwise") ? cities[1][1] : cities[1][0];
    int neighbor;
    for(int i=0; i<n; i++) {
        // road exists, next --> current
        // not, current --> next
        if(roads[{current, next}] == 0) 
            cost += roads[{next, current}];    
        neighbor = (cities[next][0] == current) ? cities[next][1] : cities[next][0];
        current = next;
        next = neighbor;
    }
    return cost;
}

int main() {
    int testCaseCount;
    int n, a, b, c;
    int current, next, neighbor;
    int antiClockwiseCost, clockwiseCost, minimumCost;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;

        vector<int> cities[n+1];
        map<pair<int,int>, int> roads;
        for(int i=0; i<n; i++){
            cin >> a >> b >> c;
            cities[a].push_back(b);
            cities[b].push_back(a);
            roads[{a, b}] = c;
        }

        antiClockwiseCost = redirect(n, cities, roads, "anti-clockwise");
        clockwiseCost = redirect(n, cities, roads, "clockwise");
        minimumCost = min(antiClockwiseCost, clockwiseCost);

        cout << "Case " << testCase << ": " << minimumCost << endl;
    }

    return 0;
}