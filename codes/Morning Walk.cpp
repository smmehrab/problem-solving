#include<bits/stdc++.h>
#include<iostream>
#include <list>
#include<cstdio>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

    void dfs(int v, bool visited[]);

    public:
        Graph(int V);

	void addEdge(int v, int w);
	int findStatus();
	bool isAllEdgesConnected();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}


bool Graph::isAllEdgesConnected(){
	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;

	for (i = 0; i < V; i++)
		if (adj[i].size() != 0)
			break;

	if (i == V)
		return true;

	dfs(i, visited);

	for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() != 0)
			return false;

	return true;
}

int Graph::findStatus(){
	if (isAllEdgesConnected() == false)
		return 0;

	int oddDegree = 0;
	for (int i = 0; i < V; i++){
		if (adj[i].size() & 1)
			oddDegree++;
	}

    if(oddDegree==0)
        return 1;
    else
        return 0;
}


int main(){
    int n, m, u, v, status;
    while(scanf("%d %d", &n, &m) != EOF){
        Graph g(n);
        for(int i=0;i<m;i++){
            cin >> u >> v;
            g.addEdge(u, v);
        }

        if(m!=0) status = g.findStatus();
        else status = 0;

        if (status)
            cout << "Possible" << endl;
        else
            cout << "Not Possible" << endl;
    }
	return 0;
}




