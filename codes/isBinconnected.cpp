/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include <list>
#define NIL -1
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool isBCUtil(int v, bool visited[], int disc[], int low[], int parent[]);

    public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isBC();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::isBCUtil(int u, bool visited[], int disc[],int low[],int parent[]){
	static int time = 0;

	int children = 0;

	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i){
		int v = *i;

		if (!visited[v]){
			children++;
			parent[v] = u;

			if (isBCUtil(v, visited, disc, low, parent))
			return true;

			low[u] = min(low[u], low[v]);


			if (parent[u] == NIL && children > 1)
			return true;


			if (parent[u] != NIL && low[v] >= disc[u])
			return true;
		}

		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
	return false;
}


bool Graph::isBC(){
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];

	for (int i = 0; i < V; i++){
		parent[i] = NIL;
		visited[i] = false;
	}

	if (isBCUtil(0, visited, disc, low, parent) == true)
		return false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

int main(){
	Graph g1(2);
	g1.addEdge(0, 1);
	g1.isBC()? cout << "Yes\n" : cout << "No\n";

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(2, 4);
	g2.isBC()? cout << "Yes\n" : cout << "No\n";

	Graph g3(3);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.isBC()? cout << "Yes\n" : cout << "No\n";

	Graph g4(5);
	g4.addEdge(1, 0);
	g4.addEdge(0, 2);
	g4.addEdge(2, 1);
	g4.addEdge(0, 3);
	g4.addEdge(3, 4);
	g4.isBC()? cout << "Yes\n" : cout << "No\n";

	Graph g5(3);
	g5.addEdge(0, 1);
	g5.addEdge(1, 2);
	g5.addEdge(2, 0);
	g5.isBC()? cout << "Yes\n" : cout << "No\n";

	return 0;
}

