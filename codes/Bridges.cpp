#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include <list>
#include<vector>
#define NIL -1
using namespace std;


vector<pair<int, int> > res;
bool comp(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first == p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}

class Graph{
	int V;
	list<int> *adj;
	void dfs(int v, bool visited[], int disc[], int low[], int parent[]);

    public:
	Graph(int V);
	void addEdge(int v, int w);
	void findBridges();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfs(int u, bool visited[], int disc[], int low[], int parent[]){
	static int time = 0;

	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i){
		int v = *i;

		if (!visited[v]){
			parent[v] = u;
			dfs(v, visited, disc, low, parent);
			low[u] = min(low[u], low[v]);

			if (low[v] > disc[u])
                res.push_back(make_pair(v, u));
		}
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::findBridges(){
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];

	for (int i = 0; i < V; i++){
		parent[i] = NIL;
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			dfs(i, visited, disc, low, parent);
}

int main(){
    int t, cs = 0, n, e, u, v;

    cin >> n;
    cin >> e;
    Graph g(n);
    for(int i=0; i<e; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findBridges();

    vector< pair<int, int> >::iterator it;
    for(it=res.begin();it!=res.end();it++){
        if((*it).first>(*it).second){
            int t=(*it).first;
            (*it).first = (*it).second;
            (*it).second = t;
        }
    }

    sort(res.begin(), res.end(), comp);

    for(it=res.begin();it!=res.end();it++)
        cout << (*it).first << " " << (*it).second << endl;

	return 0;
}
