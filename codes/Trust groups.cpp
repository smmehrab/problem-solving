#include<bits/stdc++.h>
#include <iostream>
#include <list>
#include <stack>
#include<iostream>
#include<ios>
#include<limits>
#include<map>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
    void dfs(int v, bool visited[]);
	void topSort(int v, bool visited[], stack<int> &Stack);

    public:
	Graph(int V);
	void addEdge(int v, int w);
	int findSccCount();
	Graph transpose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::dfs(int v, bool visited[]){
	visited[v] = true;
	//cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfs(*i, visited);
}

void Graph::topSort(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			topSort(*i, visited, Stack);
	Stack.push(v);
}

Graph Graph::transpose(){
	Graph g(V);
	for (int v = 0; v < V; v++){
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
			g.adj[*i].push_back(v);
	}
	return g;
}

int Graph::findSccCount(){
	stack<int> Stack;
	bool *visited = new bool[V];

	for(int i = 0; i < V; i++)
		visited[i] = false;

	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			topSort(i, visited, Stack);

	Graph gt = transpose();

	for(int i = 0; i < V; i++)
		visited[i] = false;

    int cnt = 0;
	while (Stack.empty() == false){
		int v = Stack.top();
		Stack.pop();

		if (visited[v] == false){
			gt.dfs(v, visited);
			cnt++;
			//cout << endl;
		}
	}

	return cnt;
}

int main(){
    int p, t, key, ans;
    string employee, trusts, trusted;

    while(true){
        cin >> p >> t;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if(p == 0 && t == 0)
            break;

        map<string, int> mp;
        key = 0;

        for(int i = 0; i < p; i++){
            getline(cin, employee);
            if(mp.find(employee)==mp.end())
                mp[employee]=key++;
        }

        Graph g(key);

        for(int i=0; i<t; i++){
            getline(cin, trusts);
            getline(cin, trusted);
            g.addEdge(mp[trusts], mp[trusted]);
        }

        ans = g.findSccCount();
        cout << ans << endl;
    }
	return 0;
}
