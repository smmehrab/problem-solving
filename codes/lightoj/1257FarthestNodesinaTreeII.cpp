#include<bits/stdc++.h>
using namespace std;

void bfs(int u, vector<vector<pair<int, int>>>& edges, vector<int>& distances) {
    queue<int> q;
    int v, w;

    distances[u] = 0;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(pair<int, int> edge : edges[u]) {
            v = edge.first;
            w = edge.second;
            if(distances[v]==-1){
                distances[v] = distances[u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    int testCaseCount, n, u, v, w;
    int farthest1, farthest2, distance;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;

        vector<vector<pair<int, int>>> edges;   
        for(int i=0; i<n; i++) 
            edges.push_back(vector<pair<int, int>>());
        vector<int> distances1(n, -1);
        vector<int> distances2(n, -1);
 
        for(int i=0; i<n-1; i++) {
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        bfs(0, edges, distances1);
        distance = -1;
        for(int i=0; i<n; i++) {
            if(distances1[i]>distance) {
                farthest1 = i;
                distance = distances1[i];
            }
        }    
    
        distances1 = vector<int>(n, -1);
        bfs(farthest1, edges, distances1);
        distance = -1;
        for(int i=0; i<n; i++) {
            if(distances1[i]>distance) {
                farthest2 = i;
                distance = distances1[i];
            }
        }
    
        bfs(farthest2, edges, distances2);

        cout << "Case " << testCase << ":" << endl;
        for(int i=0; i<n; i++) 
            cout << max(distances1[i], distances2[i]) << endl;
    }

    return 0;
}