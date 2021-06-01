/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
#include<iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int *inDeg;

    void dfs(int v, bool visited[]);

    public:
        Graph(int V);

	void addEdge(int v, int w);
	int findStatus();
	bool isAllEdgesConnected();
	Graph transpose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];

    inDeg = new int[V];
	for (int i = 0; i < V; i++)
        inDeg[i] = 0;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	inDeg[w]++;
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}

Graph Graph::transpose(){
	Graph g(V);
	for (int v = 0; v < V; v++){
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
			g.addEdge(*i, v);
	}
	return g;
}



bool Graph::isAllEdgesConnected(){
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	int n;
	for (n = 0; n < V; n++)
		if (adj[n].size() > 0)
            break;

	dfs(n, visited);

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	Graph gt = transpose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	gt.dfs(n, visited);

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	return true;
}

int Graph::findStatus(){
	if (isAllEdgesConnected() == false)
		return 0;

	for (int i = 0; i < V; i++)
		if (adj[i].size() != inDeg[i])
			return 0;

	return 1;
}


int main(){

    int n, m, u, v;

    cin >> n;
    cin >> m;

    Graph g(n);

    for(int i=0;i<m;i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

	int status = g.findStatus();

    cout << status << endl;


	return 0;
}

