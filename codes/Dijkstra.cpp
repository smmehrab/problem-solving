#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<int> dijkstra(int source, int n, vector<pair<int, int>> connections[]){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distances(n, INF);
	int u, v, w;

	distances[source] = 0;
	pq.push({distances[source], source});
	while (!pq.empty()){
		u = pq.top().second;
		pq.pop();
		for (pair<int, int> connection : connections[u]) {
			v = connection.first;
			w = connection.second;
			if (distances[v] > distances[u] + w){
				distances[v] = distances[u] + w;
				pq.push(make_pair(distances[v], v));
			}
		}
	}

	return distances;
}

int main() {
	int n, m, u, v, w;
	cin >> n >> m;

	vector<pair<int, int> > connections[n];
	for(int i=0; i<m; i++) {
		cin >> u >> v;
		connections[u].push_back({v, w});
		connections[v].push_back({u, w});
	}

	vector<int> distances = dijkstra(0, n, connections);

	cout << "Shortest Path from Source" << endl;
	for (int i=0; i<n; ++i)
		cout << i << " \t\t " << distances[i] << endl;

	return 0;
}