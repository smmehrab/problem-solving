/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;

int count = 0;

class Edge {
    public:
    int u;
	int v;
	Edge(int u, int v);
};

Edge::Edge(int u, int v){
	this->u = u;
	this->v = v;
}

class Graph {
	int V;
	int E;
	list<int>* adj;

	void dfs(int u, int disc[], int low[], list<Edge>* st, int parent[]);

    public:
	Graph(int V);
	void addEdge(int v, int w);
	void findBcc();
};

Graph::Graph(int V){
	this->V = V;
	this->E = 0;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	E++;
}

void Graph::dfs(int u, int disc[], int low[], list<Edge>* st, int parent[]){
	static int time = 0;

	disc[u] = low[u] = ++time;
	int children = 0;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i) {
		int v = *i;

		if (disc[v] == -1) {
			children++;
			parent[v] = u;

			st->push_back(Edge(u, v));
			dfs(v, disc, low, st, parent);

			low[u] = min(low[u], low[v]);

			if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
				while (st->back().u != u || st->back().v != v) {
					cout << st->back().u << "--" << st->back().v << " ";
					st->pop_back();
				}

				cout << st->back().u << "--" << st->back().v;
				st->pop_back();

				cout << endl;
				count++;
			}
		}

		else if (v != parent[u]) {
			low[u] = min(low[u], disc[v]);
			if (disc[v] < disc[u])
				st->push_back(Edge(u, v));
		}
	}
}

void Graph::findBcc(){
	int* disc = new int[V];
	int* low = new int[V];
	int* parent = new int[V];
	list<Edge>* st = new list<Edge>[E];

	for (int i = 0; i < V; i++) {
		disc[i] = NIL;
		low[i] = NIL;
		parent[i] = NIL;
	}

	for (int i = 0; i < V; i++) {
		if (disc[i] == NIL)
			dfs(i, disc, low, st, parent);

		int j = 0;
		while (st->size() > 0) {
			j = 1;
			cout << st->back().u << "--" << st->back().v << " ";
			st->pop_back();
		}

		if (j == 1) {
			cout << endl;
			count++;
		}
	}
}

int main(){
	Graph g(12);
	g.addEdge(0, 1);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(1, 3);
	g.addEdge(3, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 2);
	g.addEdge(2, 4);
	g.addEdge(4, 2);
	g.addEdge(3, 4);
	g.addEdge(4, 3);
	g.addEdge(1, 5);
	g.addEdge(5, 1);
	g.addEdge(0, 6);
	g.addEdge(6, 0);
	g.addEdge(5, 6);
	g.addEdge(6, 5);
	g.addEdge(5, 7);
	g.addEdge(7, 5);
	g.addEdge(5, 8);
	g.addEdge(8, 5);
	g.addEdge(7, 8);
	g.addEdge(8, 7);
	g.addEdge(8, 9);
	g.addEdge(9, 8);
	g.addEdge(10, 11);
	g.addEdge(11, 10);
	g.findBcc();
	cout << "Above are " << count << " biconnected components in graph";
	return 0;
}
