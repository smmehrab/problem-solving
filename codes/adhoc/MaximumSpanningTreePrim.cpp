#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int numberOfVertices;
	vector<vector<pair<int, int>>> edges;

public:
	Graph(int numberOfVertices) {
		this->numberOfVertices = numberOfVertices;
		edges = vector<vector<pair<int, int>>>(numberOfVertices, vector<pair<int, int>>());
	}

	void addEdge(int source, int destination, int weight) {
		edges[source].push_back({destination, weight});
		edges[destination].push_back({source, weight});
	}

	void maximumSpanningTree() {
		priority_queue<pair<int, int>> pq;
		vector<bool> visited(numberOfVertices, false);
		vector<int> parent(numberOfVertices, -1);
		vector<int> maxWeightToConnect(numberOfVertices, INT_MIN);

		pq.push({0, 0});
		maxWeightToConnect[0] = 0;

		while(!pq.empty()) {
			int current = pq.top().second;
			pq.pop();

			visited[current] = true; 
			for(pair<int, int> adjacent : edges[current]) {
				int node = adjacent.first;
				int weight = adjacent.second;
				if (!visited[node] && maxWeightToConnect[node]<weight) {
					maxWeightToConnect[node] = weight;
					pq.push({maxWeightToConnect[node], node});
					parent[node] = current;
				}
			}
		}

		for (int node=1; node<numberOfVertices; node++)
			cout << parent[node] << " - " << node << endl;
	}
};

int main() {
	int numberOfVertices = 9, numberOfEdges;
	int source, destination, weight;

	cout << "Enter Number Of Vertices:" << endl;
	cin >> numberOfVertices;

	Graph graph(numberOfVertices);

	cout << "Enter Number Of Edges:" << endl;
	cin >> numberOfEdges;

	cout << "Enter " << numberOfEdges << " Edges: (source destination weight)" << endl;
	for(int edge=0; edge<numberOfEdges; edge++) {
		cin >> source >> destination >> weight;
		graph.addEdge(source, destination, weight);
	}

	graph.maximumSpanningTree();
	return 0;
}

/*
Input:
5
7
0 3 6
0 1 2
1 3 8
1 2 3
1 4 5
2 4 7
3 4 9

Output:
3 - 1
4 - 2
0 - 3
3 - 4
*/