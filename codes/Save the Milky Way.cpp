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
	bool *ap;
	void dfs(int v, bool visited[], int d[], int low[], int p[]);

    public:
        Graph(int V);

	void addEdge(int v, int w);
	void findAp();
	bool isAp(int a);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
    ap = new bool[V];

    for(int i = 0;i<V;i++)
        ap[i] = false;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}


void Graph::dfs(int u, bool visited[], int d[], int low[], int p[]){
	static int time = 0;
	int child = 0;

	visited[u] = true;

	d[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i){
		int v = *i;

		if (!visited[v]){
			child++;
			p[v] = u;
			dfs(v, visited, d, low, p);

			low[u] = min(low[u], low[v]);

			if (p[u] == NIL && child > 1)
                ap[u] = true;

			if (p[u] != NIL && low[v] >= d[u])
                ap[u] = true;
		}

		else if (v != p[u])
			low[u] = min(low[u], d[v]);
	}
}

void Graph::findAp(){
	bool *visited = new bool[V];
	int *d = new int[V];
	int *low = new int[V];
	int *p = new int[V];

	for (int i = 0; i < V; i++){
		p[i] = NIL;
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			dfs(i, visited, d, low, p);
}

bool Graph::isAp(int a){
    return ap[a];
}

int main(){

    int n, e, q, a, u, v;

    cin >> n >> e;

    Graph g(n);
    for(int i=0;i<e;i++){
        cin >> u >> v;
        g.addEdge(u-1, v-1);
    }

	g.findAp();
	cin >> q;
	while(q--){
        cin >> a;
        if(g.isAp(a-1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}

	return 0;
}
