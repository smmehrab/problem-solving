#include<bits/stdc++.h>
using namespace std;

#define N 105

vector<pair<int, pair<int, int>>> g;
map<string, int> id;
int parent[N];

int findRoot(int x) {
    if(x != parent[x])
        parent[x] = findRoot(parent[x]);
    return parent[x];
}

long long int kruskal(int n) {
    int u, v, w, uRoot, vRoot, root=-1;
    long long int cost;
    
    sort(g.begin(), g.end());
    cost = 0;
    for(pair<int, pair<int, int>> road : g) {
        u = road.second.first;
        v = road.second.second;
        w = road.first;
        uRoot = findRoot(u);
        vRoot = findRoot(v);
        // Union
        if(uRoot != vRoot) {
            cost += w; 
            parent[uRoot] = parent[vRoot]; 
        }
    }

	for(int i=0; i<n;i++) {
        if(i==0)
            root = findRoot(0);
		else if(findRoot(i)!=root)
		    return -1;
	}
	return cost;
}

int main() {
    int testCaseCount, n, m, w;
    string city1, city2;
    long long int minimumCost;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> m;

        id.clear();
        g.clear();

        for(int i=0; i<m; i++) {
            cin >> city1 >> city2 >> w;
            if(id.find(city1)==id.end())
                id[city1] = id.size();
            if(id.find(city2)==id.end())
                id[city2]=id.size();
            g.push_back({w, {id[city1],id[city2]}});
        }

        n = id.size();
        for(int i=0; i<n+1; i++)
            parent[i] = i;

        minimumCost = kruskal(id.size());
        cout << "Case " << testCase << ": " << (minimumCost==-1 ? "Impossible" : to_string(minimumCost)) << endl;
	}

	return 0;
}