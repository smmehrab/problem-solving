#include <bits/stdc++.h>
using namespace std;

#define N 100100

vector<int> graph[N];
int color[N]; 
bool visited[N];

bool bfs(int start) {
    queue<int> q;
    int u;

    color[start] = 1;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        u = q.front(); 
        q.pop();
        for(int adjacent : graph[u]){
            if(color[u] == color[adjacent])
                return false;
            if(!visited[adjacent]){
                visited[adjacent] = true;
                color[adjacent] = 3 - color[u]; 
                q.push(adjacent);
            }
        }
    }
    return true;
}

bool isBipartite(int n) {
    for(int i=0; i<n; i++) {
        if(!visited[i] && !bfs(i))
            return false;
    }
    return true;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;    
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(isBipartite(n)) {
        for(int j=0; j<n; j++)
            cout << color[j] << " ";
    }
    else 
        cout << "IMPOSSIBLE" << endl;

    return 0;
}