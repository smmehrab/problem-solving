#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<bits/stdc++.h>
#include<vector>


using namespace std;

#define INF INT_MAX
typedef pair<int, int> intPair;

struct Edge{
    int source, destination, weight;
};

void addEdge(vector<intPair> adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}

void shortestPath(vector<intPair> adj[], int V, int E, int src, int dest, struct Edge* edge){
    priority_queue<intPair> pq;
    vector<int> dist(V, 0);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        vector<intPair>::iterator i;
        for(i = adj[u].begin();i!=adj[u].end();++i){
            int v=(*i).first;
            int weight=(*i).second;

            int j;
            for(j=0; j<E; j++)
                if(edge[j].source==u && edge[j].destination == v)
                    break;

            if(edge[j].weight==1){
                edge[j].weight=-1;
                dist[v]++;
                pq.push(make_pair(dist[v], v));
            }

            /*
            int temp = (dist[u]+weight);
            if(dist[v] > temp){
                dist[v] = temp;
                pq.push(make_pair(dist[v], v));
            }
            */


        }
    }

    cout << dist[dest] << endl;

}


int main(){
    int V,E, u , v, c, q;

    cin >> V >> E;

    vector<intPair> adj[V];
    struct Edge* edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    for(int i=0; i<E; i++){
        cin >> u >> v;
        addEdge(adj, u-1, v-1, 1);
        edge[i].source = u-1;
        edge[i].destination = v-1;
        edge[i].weight = 1;
    }


    cin >> q;
    while(q--){
        cin >> u >> v;
        shortestPath(adj, V, E, u-1, v-1, edge);
        for(int i=0; i<E; i++)
            edge[i].weight=1;
    }

    return 0;
}

