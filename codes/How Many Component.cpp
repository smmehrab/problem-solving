/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;

int cnt = 0;

class Graph {
    int V;
    list<int>* adj;

    void dfs(int u, int disc[], int low[], int parent[]);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void findBcc();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::dfs(int u, int disc[], int low[], int parent[]){
    static int time = 0;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;

        if (disc[v] == -1) {
            parent[v] = u;

            dfs(v, disc, low, parent);

            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u])
                cnt++;
        }

        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void Graph::findBcc(){
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];

    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }

    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            dfs(i, disc, low, parent);
}

int main(){
    int n, e, u, v;
    cin >> n;
    cin >> e;

    Graph g(n);
    for(int i=0; i<e; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findBcc();
    cout << cnt << endl;
    return 0;
}
