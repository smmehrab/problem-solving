/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int s, d, w;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

bool ifNegativeCycleExists(struct Graph* graph, int s){
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[s] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].s;
            int v = graph->edge[j].d;
            int w = graph->edge[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].s;
        int v = graph->edge[i].d;
        int w = graph->edge[i].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return true;
    }

    return false;
}

int main(){
    int V, E, s, d, w;

    cin >> V >> E;
    struct Graph* graph = createGraph(V, E);

    for(int i=0; i<E; i++){
        cin >> s >> d >> w;
        graph->edge[i].s = s;
        graph->edge[i].d = d;
        graph->edge[i].w = w;
    }

    if (ifNegativeCycleExists(graph, 0))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
