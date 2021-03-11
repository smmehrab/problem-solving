#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<stack>
using namespace std;
vector<pair<int, int> > res;

bool comp(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}

class Graph{
    int V;
    int E;
    list<int>* adj;
    void dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void findBridges();
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]){
    static int time=0;
    disc[u] = low[u] = ++time;
    visited[u]=true;
    int children=0;

    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i){
        int v=*i;
        if(!visited[v]){
            children++;
            parent[v]=u;

            dfs(v, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if(parent[u]==-1 && children>1){
                if(low[v]>disc[u])
                    res.push_back(make_pair(u, v));
            }

            else if(low[v]>disc[u])
                res.push_back(make_pair(u, v));
        }

        else if(v!=parent[u])
            low[u]=min(low[u], disc[v]);
    }
}

void Graph::findBridges(){
    bool* visited = new bool[V];
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    bool* ap = new bool[V];

    for(int i=0; i<V; i++){
        parent[i]=-1;
        visited[i]=false;
        ap[i]=false;
    }

    for(int i=0; i<V; i++){
        if(!visited[i])
            dfs(i, visited, disc, low, parent, ap);
    }


    sort(res.begin(), res.end(), comp);
    for(int j=0;j<res.size();++j)
        cout << res[j].first << " " << res[j].second << endl;
}

int main(){
    int n, m, u, v;

    cin >> n;
    cin >> m;

    Graph g(n);

    for(int i=0; i<m; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findBridges();
    return 0;
}
