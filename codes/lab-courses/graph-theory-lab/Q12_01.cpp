/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<bits/stdc++.h>
#include<vector>


using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> intPair;


void addEdge(vector<intPair> adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void shortestPath(vector<intPair> adj[], int V, int src, int dest){
    priority_queue<intPair> pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        vector<intPair>::iterator i;
        for(i = adj[u].begin();i!=adj[u].end();++i){
            int v=(*i).first;
            int weight=(*i).second;

            int temp = (dist[u]|weight);
            if(dist[v] > temp){
                dist[v] = temp;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


    if(dist[dest]==INF)
        cout << -1 << endl;

    else
        cout << dist[dest] << endl;

}


int main(){
    int V,E, u , v, c, q;

    cin >> V >> E;

    vector<intPair> adj[V];

    for(int i=0; i<E; i++){
        cin >> u >> v >> c;
        addEdge(adj, u-1, v-1, c);
    }


        cin >> u >> v;
        shortestPath(adj, V, u-1, v-1);

    return 0;
}
