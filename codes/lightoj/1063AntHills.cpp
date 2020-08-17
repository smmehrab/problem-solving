#include<iostream>
#include <list>
#define NIL -1
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void dfs(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

    public:
	Graph(int V);
	void addEdge(int v, int w);
	int apCount();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]){
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

			dfs(v, visited, disc, low, parent, ap);

			low[u] = min(low[u], low[v]);

			if (parent[u] == NIL && children > 1)
                ap[u] = true;
			if (parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;
		}

		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

int Graph::apCount(){
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V];
	int res = 0;

	for (int i = 0; i < V; i++){
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			dfs(i, visited, disc, low, parent, ap);

	for (int i = 0; i < V; i++){
		if (ap[i] == true)
			res++;
	}

    return res;
}

int main(){
    int t, n, m, a, b, cs = 0, ans = 0;

    cin >> t;

    while(t--){
        cin >> n >> m;
        Graph g(n);

        for(int i = 0; i<m; i++){
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }

        ans = g.apCount();
        cout << "Case " << ++cs << ": "  << ans << endl;
    }

	return 0;
}
