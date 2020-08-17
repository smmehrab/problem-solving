#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	void topSort(int v, bool visited[], stack<int> &Stack);
	void dfs(int v, bool visited[]);

    public:
        Graph(int V);

	void addEdge(int v, int w);
	void findGroups();
	Graph transpose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}

Graph Graph::transpose(){
	Graph gt(V);
	for (int v = 0; v < V; v++){
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
			gt.adj[*i].push_back(v);
	}
	return gt;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::topSort(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			topSort(*i, visited, Stack);
	Stack.push(v);
}

void Graph::findGroups(){
	stack<int> Stack;
	bool *visited = new bool[V];

	for(int i = 0; i < V; i++)
		visited[i] = false;

	for(int i = 0; i < V; i++)
		if(!visited[i])
			topSort(i, visited, Stack);

	Graph gt = transpose();

	for(int i = 0; i < V; i++)
		visited[i] = false;

	while (Stack.empty() == false){
		int v = Stack.top();
		Stack.pop();

		if (visited[v] == false){
			gt.dfs(v, visited);
			cout << endl;
		}
	}
}

int main(){
    int n, e, q, a, u, v;

    cin >> n >> e;

    Graph g(n);
    for(int i=0;i<e;i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

	g.findGroups();

	return 0;
}
