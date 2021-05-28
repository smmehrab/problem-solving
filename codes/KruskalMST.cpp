#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;

vector<pair<long long int, pair<int, int>>> edges;
int parent[MAX];

void init(){
    for(int i=0; i<MAX; i++)
        parent[i] = i;
}

int findRoot(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

long long int kruskal(vector<pair<long long int, pair<int, int>>>& edges){
    int u, v, uRoot, vRoot;
    long long int w, minimumCost = 0;
    for(pair<long long int, pair<int, int>> edge : edges){
        u = edge.second.first;
        v = edge.second.second;
        w = edge.first;
        uRoot = findRoot(u);
        vRoot = findRoot(v);
        if(uRoot != vRoot){
            minimumCost += w;
            parent[uRoot] = parent[vRoot];
        }
    }
    return minimumCost;
}

int main(){
    int n, m, u, v, w;
    long long int w, minimumCost;

    init();

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());
    minimumCost = kruskal(edges);

    cout << minimumCost << endl;
    return 0;
}