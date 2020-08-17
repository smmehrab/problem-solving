#include<iostream>
#include <list>
#include <stack>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

class Graph{
	int V;
	list<int> *adj;

	void dfs(int v, bool visited[], stack<int> &Stack);
    bool colorGraph(int u, int color[]);

    public:
	Graph(int V);

	void addEdge(int v, int w);
	void topSort();
	bool isCyclic();
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
		cout << Stack.top()+1 << endl;
		Stack.pop();
	}
}

bool Graph::colorGraph(int u, int color[]){
    color[u] = GRAY;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (color[v] == GRAY)
          return true;
        if (color[v] == WHITE && colorGraph(v, color))
          return true;
    }
    color[u] = BLACK;
    return false;
}

bool Graph::isCyclic(){
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;


    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
           if (colorGraph(i, color) == true)
              return true;
    return false;
}

int main(){

    int n, m, u, v;

    while(true){
        cin >> n >> m;
        if(n==0 && m==0)
            break;

        Graph g(n);
        for(int i=0;i<m;i++){
            cin >> u >> v;
            g.addEdge(u-1, v-1);
        }

        if(g.isCyclic())
            cout << "IMPOSSIBLE" << endl;
        else
            g.topSort();
    }

	return 0;
}
