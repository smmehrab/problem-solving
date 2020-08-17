#include<iostream>
#include<list>
#include <stack>
using namespace std;

class Graph{
	int n;
	list<int> *adj;
	void dfs(int s, bool visited[]);

    public:
    Graph(int n);
	void addEdge(int a, int b);
	int componentCount(int n);
    void topSort(int v, bool visited[], stack<int> &Stack);
};

Graph::Graph(int n){
	this->n = n;
	adj = new list<int>[n];
}

void Graph::addEdge(int a, int b){
	adj[a].push_back(b);
}

void Graph::topSort(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topSort(*i, visited, Stack);

	Stack.push(v);
}


void Graph::dfs(int s, bool visited[]){
	visited[s] = true;
	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}

int Graph::componentCount(int n){
    stack<int> Stack;
	bool *visited = new bool[n];
	int temp;

	for (int i = 0; i < n; i++)
        if (!visited[i])
            topSort(i, visited, Stack);

	for (int i = 0; i < n; i++)
		visited[i] = false;

    int cnt = 0;
	while (Stack.empty() == false){
		temp = Stack.top();
		Stack.pop();
		if(!visited[temp]){
            dfs(temp, visited);
            cnt++;
		}
	}

	return cnt;
}

int main(){
    int t, cs = 0;
    int n, m, a, b, ans;

    cin >> t;
    while(t--){
        cin >> n >> m;
        Graph g(n);
        while(m--){
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }
        ans = g.componentCount(n);
        cout << "Case " << ++cs << ": " << ans << endl;
    }
	return 0;
}
