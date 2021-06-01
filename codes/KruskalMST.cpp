/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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
    sort(edges.begin(), edges.end());
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

    minimumCost = kruskal(edges);

    cout << minimumCost << endl;
    return 0;
}