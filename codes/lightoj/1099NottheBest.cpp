#include<bits/stdc++.h>
using namespace std;

# define INF INT_MAX

void dijkstra(int source, vector<int>& d, vector<pair<int, int>> graph[], int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int u, v, w;

	d[source] = 0;
	pq.push({d[source], source});
	while(!pq.empty()) {
		u = pq.top().second;
		pq.pop();
		for(pair<int, int> adjacent : graph[u]){
			v = adjacent.first;
			w = adjacent.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
}

int main() {
	int testCaseCount;
    int n, r, u, v, w;
    int d, shortest, secondShortest;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> r;

        vector<pair<int, int>> graph[n];
	    vector<int> dSource(n, INF);
	    vector<int> dDestination(n, INF);

        for(int i=0; i<r; i++) {
            cin >> u >> v >> w;
            u--, v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});        
        }

        dijkstra(0, dSource, graph, n);
        dijkstra(n-1, dDestination, graph, n);

        shortest = dSource[n-1];
        secondShortest = INF;
        for(u=0; u<n; u++) {
            for(pair<int, int> adjacent : graph[u]) {
                v = adjacent.first;
                w = adjacent.second;
                d = dSource[u] + w + dDestination[v];
                if(d>shortest) 
                    secondShortest = min(secondShortest, d);
            }
        }

        cout << "Case " << testCase << ": " << secondShortest << endl;
    }

	return 0;
}