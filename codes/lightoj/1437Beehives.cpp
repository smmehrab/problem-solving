/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int findShortestCycle(int n, vector<int> adjacents[]) {
    int node;
	int nodeCount = INT_MAX;

    // For All Nodes
	for (int i=0; i<n; i++) {
		queue<int> q;
		vector<int> level(n, (int)(1e9));
		vector<int> parents(n, -1);

        // BFS
		level[i] = 0;
		q.push(i);
		while (!q.empty()) {
			node = q.front();
			q.pop();

			for (int adjacent : adjacents[node]) {
				if (level[adjacent] == (int)(1e9)) {
					level[adjacent] = 1 + level[node];
					parents[adjacent] = node;
					q.push(adjacent);
				}
				else if (parents[node] != adjacent && parents[adjacent] != node)
					nodeCount = min(nodeCount, level[node] + level[adjacent] + 1);
			}
		}
	}

	return (nodeCount == INT_MAX) ? -1 : nodeCount;
}

int main() {
    int testCaseCount;
    int n, m, u, v;
    int shortestCycle;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> m;

        vector<int> adjacents[n];
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            adjacents[u].push_back(v);
	        adjacents[v].push_back(u);
        }

        shortestCycle = findShortestCycle(n, adjacents);

        cout << "Case " << testCase << ": ";
        cout << ((shortestCycle==-1) ? "impossible" : to_string(shortestCycle)) << endl;
    }

	return 0;
}