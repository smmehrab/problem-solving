#include <iostream>
#include <list>
#include <stack>
using namespace std;

list<int> *scc;
int sccCount;

class Graph{
	int V;
	list<int> *adj;
	int *inDeg;

	void topsort(int v, bool visited[], stack<int> &Stack);
	void dfs(int v, bool visited[]);

    public:
	Graph(int V);

	void addEdge(int v, int w);
	void findSCCs();
	Graph getTranspose();
	int findSccZeroInCount();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
    scc = new list<int>[V];
    sccCount=0;

    inDeg = new int[V];
	for (int i = 0; i < V; i++)
        inDeg[i] = 0;
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;
	scc[sccCount].push_back(v);

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}

Graph Graph::getTranspose(){
	Graph g(V);
	for (int v = 0; v < V; v++){
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
			g.adj[*i].push_back(v);
	}
	return g;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	inDeg[w]++;
}

void Graph::topsort(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			topsort(*i, visited, Stack);
	Stack.push(v);
}

void Graph::findSCCs(){
	stack<int> Stack;

	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			topsort(i, visited, Stack);

	Graph gt = getTranspose();

	for(int i = 0; i < V; i++)
		visited[i] = false;

	while (Stack.empty() == false){
		int v = Stack.top();
		Stack.pop();

		if (visited[v] == false){
			gt.dfs(v, visited);
            sccCount++;
		}
	}
}

int Graph::findSccZeroInCount(){
    int zeroInCount = 0;
    int c = 0;

    list<int>::iterator j;
	for(int i=0;i<sccCount;i++){
        c=0;
	    for(j=scc[i].begin();j!=scc[i].end();++j)
            c += inDeg[*j];

        if( scc [ i ] . size() != 1 )
            c-=scc[i].size();

        if(c==0)
            zeroInCount++;
	}

    return zeroInCount;
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

	g.findSCCs();

    int zeroInCount = g.findSccZeroInCount();

    //g.printAll();

    if(zeroInCount>=2)
        cout << 0 << endl;
    else
        cout<<scc[0].size()<<endl;

	return 0;
}
