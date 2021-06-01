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
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	void dfs(int v, bool visited[], stack<int> &Stack);

    public:
	Graph(int V);

	void addEdge(int v, int w);
	void topSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::dfs(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited, Stack);

	Stack.push(v);
}

void Graph::topSort(){
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
        if (visited[i] == false)
            dfs(i, visited, Stack);

	while (Stack.empty() == false){
		cout << Stack.top() << endl;
		Stack.pop();
	}
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

	g.topSort();

	return 0;
}
