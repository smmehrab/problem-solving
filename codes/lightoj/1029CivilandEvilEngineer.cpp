#include<bits/stdc++.h>
using namespace std;

#define N 105

vector<pair<int, pair<int, int>>> connections;
int parent[N];

int findRoot(int x) {
    if(x != parent[x])
        parent[x] = findRoot(parent[x]);
    return parent[x];
}

int kruskal(string flag) {
    int u, v, w, uRoot, vRoot, cost;

    sort(connections.begin(), connections.end());
    if(flag=="maximum")
        reverse(connections.begin(),connections.end());

    cost =0;
    for(pair<int, pair<int, int>> connection : connections) {
        u = connection.second.first;
        v = connection.second.second;
        w = connection.first;
        uRoot = findRoot(u);
        vRoot = findRoot(v);
        // Union
        if(uRoot != vRoot) {
            cost += w; 
            parent[uRoot] = parent[vRoot]; 
        }
    }

    return cost;
}

int main() {
    int testCaseCount;
    int n, u, v, w;
    int best, worst, sum;
    string output;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;
        
        connections.clear();
        while(cin >> u >> v >> w) {
            if(u==0 && v==0 && w==0)
                break;
            connections.push_back({w, {u, v}});
        }

        for(int i=0; i<n+1; i++)
            parent[i] = i;
        best = kruskal("minimum");

        for(int i=0; i<n+1; i++)
            parent[i] = i;
        worst = kruskal("maximum");
        
        sum = best+worst;
        output = (sum%2==0) ? to_string(sum/2) : (to_string(sum)+"/2"); 
        cout << "Case " << testCase << ": " << output << endl;
    }

    return 0;
}