#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int n, sx, sy, dx, dy, shortest_route;
int x[10], y[10], visited[10];

int get_distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void explore(int current, int cost, int node_left) {
    if(node_left == 1) {
        if(cost + get_distance(x[current], y[current], dx, dy) < shortest_route)
            shortest_route = cost + get_distance(x[current], y[current], dx, dy);
        return;
    }

    visited[current] = 1;
    for(int i=0;i<n;i++) {
        if(visited[i] == 0)
            explore(i, cost + get_distance(x[current], y[current], x[i], y[i]), node_left-1);
    }
    visited[current] = 0;
}

int main() {
    int i, testcases = 10;
    while (testcases--) {
        cin >> n;
        cin >> sx >> sy >> dx >> dy;
        for(i=0;i<n;i++) {
            cin >> x[i] >> y[i];
            visited[i] = 0;
        }
        shortest_route = INT_MAX;
        for(i=0;i<n;i++) {
            explore(i, get_distance(x[i], y[i], sx, sy), n);
        }
        cout << "# " << (10-testcases) << " " << shortest_route << endl;
    }
    return 0;
}
