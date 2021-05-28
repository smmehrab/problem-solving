#include <bits/stdc++.h>
using namespace std;

#define N 100100

vector<int> graph[N];
int parent[N]; 
int color[N]; 
bool visited[N];
vector<int> trip;
bool detected = false;

void dfs(int node, int from) {
    parent[node] = from;
    visited[node] = true;
    for(int adjacent : graph[node]) {
        if(detected)
            return;
        else if(!visited[adjacent]) 
            dfs(adjacent, node);
        else if(adjacent != from) {
            trip.push_back(node);
            while(parent[node] != adjacent) {
                node = parent[node];
                trip.push_back(node);
            }
            trip.push_back(adjacent);
            trip.push_back(trip[0]);
                
            detected = true;
            return;
        }
    }
}
 

int main() {
    int n, m, a, b;
    cin >> n >> m;    
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++) {
        if(!visited[i] && !detected)
            dfs(i,-1);
    }

    if(detected) {
        cout << trip.size() << endl;
        for(int adjacent : trip) 
            cout << adjacent <<" ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    
    return 0;
}