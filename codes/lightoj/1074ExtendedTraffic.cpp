#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
int t, cs=0, n, r, q, u, v, w;

int b[300];
int minCost[300];
bool visited[300];

vector<int>adj[300];
vector<int>weight[300];

void reset(){
    for(int i=0; i<=300; i++){
        b[i] = 0;
        minCost[i] = INF/3;
        visited[i] = false;
        adj[i].clear();
        weight[i].clear();
    }
}

void dfs(int src){
    visited[src]=true;
    for(int i=0;i<adj[src].size();i++)
        if(!visited[adj[src][i]])
            dfs(adj[src][i]);
}

void bellman_ford(int src){
    minCost[src] = 0;
    for(int k=1; k<n; k++){
        for(int i=1; i<=n; i++){
            for(int j=0; j<adj[i].size(); j++){
                v = adj[i][j];
                w = weight[i][j];
                if(minCost[v] > (minCost[i]+w))
                    minCost[v] = (minCost[i]+w);
            }
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        reset();

        cin >> n;
        for(int i=1; i<=n; i++)
            cin>>b[i];

        cin >> r;
        for(int i=1; i<=r; i++){
            cin>> u >> v;
            adj[u].push_back(v);

            int temp = (b[v]-b[u]);
            weight[u].push_back(temp*temp*temp);
        }

        bellman_ford(1);
        dfs(1);

        cin>>q;

        cout << "Case " << ++cs << ":" << endl;
        while(q--){
            cin >> v;
            if(visited[v] && minCost[v]>=3)
                cout << minCost[v] << endl;
            else
                cout << "?" << endl;
        }
    }

    return 0;

}
