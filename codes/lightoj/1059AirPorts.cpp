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
set<int> components; 
int parent[MAX];

void init(int n) {
    edges.clear();
    components.clear();
    for(int i=0; i<n; i++)
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

int main() {
    int testCaseCount;
    int n, m, a;
    int u, v, w;
    long long int totalCost, roadCost, airportCost;
    int componentCount;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++){
        cin >> n >> m >> a;

        init(n);

        for(int i=0; i<m; i++) {
            cin >> u >> v >> w;
            u--, v--;
            if(w<a) 
                edges.push_back({w, {u, v}});
        }

        roadCost = kruskal(edges);
        
        for (int i=0; i<n; i++)
            components.insert(findRoot(i));
        componentCount = components.size();

        airportCost = (componentCount*a);
        totalCost = roadCost + airportCost;
        
        cout << "Case " << testCase << ": " << totalCost << " " << componentCount << endl;
    }

    return 0;
}