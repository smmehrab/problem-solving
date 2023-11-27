#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Point{
    int x, y;
};

struct Wormhole{
    int x1, y1, x2, y2, cost;
};

int get_distance(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int n, min_cost;
Point s, d;
Wormhole w[50];
int visited[20]={0};

void solve(int x, int y, int cost){
    min_cost = min(min_cost, cost + get_distance(x, y, d.x, d.y));
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            solve(w[i].x2, w[i].y2, cost + get_distance(x,y,w[i].x1,w[i].y1) + w[i].cost);
            solve(w[i].x1, w[i].y1, cost + get_distance(x,y,w[i].x2,w[i].y2) + w[i].cost);
            visited[i]=0;
        }
    }
}

int main() {
    int testcases;
    cin >> testcases;
    for(int i=0;i<testcases;i++){
        cin >> n;
        cin >> s.x >> s.y >> d.x >> d.y;
        for(int i=0;i<n;i++)
            cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2 >> w[i].cost;
        min_cost = INT_MAX;
        solve(s.x, s.y, 0);
        cout << min_cost << endl;
    }
    return 0;
}
