#include<iostream>
#include<list>
#include<stack>
#define NIL -1;
using namespace std;

int count = 0;

class Edge{
    public:
    int u;
    int v;
    Edge(int u, int v);
};

Edge::Edge(int u, int v){
    this->u=u;
    this->v=v;
}

class Graph{
    int V;
    int E;
    list<int>* adj;
    void dfs(int u, int disc[], int low[], list<Edge>* st, int parent[]);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void findBcc();
};

Graph::Graph(int V){
    this->V=V;
    this->E=0;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
    E++;
}

void Graph::dfs(int u, int disc[], int low[], list<Edge>* st, int parent[]){
    static int time=0;
    disc[u] = low[u] = ++time;

    int children=0;

    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i){
        int v=*i;
        if(disc[v]==-1){
            children++;
            parent[v]=u;

            st->push_back(Edge(u, v));
            dfs(v, disc, low, st, parent);

            low[u] = min(low[u], low[v]);

            if((disc[u]==1 && children>1)||(disc[u]>1 && low[v]>=disc[u])){
                while(st->back().u!=u || st->back().v!=v){
                    //cout << st->back().u << "-" << st->back().v << " ";
                    st->pop_back();
                }

                //cout << st->back().u << "-" << st->back().v;
                st->pop_back();

                //cout << endl;
                count++;
            }
        }

        else if(v!=parent[u]){
            low[u]=min(low[u], disc[v]);
            if(disc[v]<disc[u])
                st->push_back(Edge(u, v));
        }
    }
}

void Graph::findBcc(){
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    list<Edge>* st = new list<Edge>[E];

    for(int i=0; i<V; i++){
        disc[i]=NIL;
        low[i]=NIL;
        parent[i]=NIL;
    }

    for(int i=0; i<V; i++){
        if(disc[i]==-1)
            dfs(i, disc, low, st, parent);

        int j=0;
        while(st->size()>0){
            j=1;
            //cout << st->back().u << "-" << st->back().v << " ";
            st->pop_back();
        }

        if(j==1){
            //cout << endl;
            count++;
        }
    }
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

    g.findBcc();
    cout << count << endl;
}
