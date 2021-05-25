#include <bits/stdc++.h>
using namespace std;

void findRoute(int source, vector<int> network[], int n) {
    vector<int> level(n+1, 0);
    vector<bool> visited(n+1, false);
    map<int, int> parent;
	queue<int> q;
    vector<int> route;

	visited[source] = true;
	level[source] = 0;
	q.push(source);
	while (!q.empty()) {
		source = q.front();
		q.pop();

        if(source == n)
            break;

		for (int neighbor : network[source]) {
			if (!visited[neighbor]) {
                parent[neighbor] = source;
                visited[neighbor] = true;
				level[neighbor] = level[source] + 1;
				q.push(neighbor);
			}
		}
	}

    if(!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        route.push_back(n);
        source = n;
        while(source != 1){
            source = parent[source];
            route.push_back(source);
        }
        reverse(route.begin(), route.end());
        cout << route.size() << endl;
        for(int node : route) 
            cout << node << " ";
    }
}

int main() {
	int n, m, a, b;
    cin >> n >> m;

	vector<int> network[n+1];
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        network[a].push_back(b);
	    network[b].push_back(a);
    }

	findRoute(1, network, n);
	return 0;
}