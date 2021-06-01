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
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
    Graph(int V);

    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    int findSource();

    void printEulerPath(int s);
    int dfsCount(int v, bool visited[]);
    bool isOnlyOrNotBridge(int u, int v);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::removeEdge(int u, int v){
    list<int>::iterator vIndex = find(adj[u].begin(), adj[u].end(), v);
    *vIndex = -1;

    list<int>::iterator uIndex = find(adj[v].begin(), adj[v].end(), u);
    *uIndex = -1;
}

int Graph::findSource(){
    int src = 0;
    for (int i = 0; i < V; i++){
        if (adj[i].size() & 1){
            src = i;
            break;
        }
    }
    return src;
}

void Graph::printEulerPath(int u){
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (v != -1 && isOnlyOrNotBridge(u, v)){
            cout << u << " " << v << endl;
            removeEdge(u, v);
            printEulerPath(v);
        }
    }
}

bool Graph::isOnlyOrNotBridge(int u, int v){
    int count = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;

    bool visited[V];
    memset(visited, false, V);

    int countBefore = dfsCount(u, visited);

    removeEdge(u, v);
    memset(visited, false, V);

    int countAfter = dfsCount(u, visited);

    addEdge(u, v);

    return (countBefore > countAfter)? false: true;
}

int Graph::dfsCount(int s, bool visited[]){
    visited[s] = true;
    int count = 1;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += dfsCount(*i, visited);
    return count;
}

int main(){
    int src;

    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    src = g1.findSource();
    g1.printEulerPath(src);

    cout  << endl << "------------" << endl;

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    src = g2.findSource();
    g2.printEulerPath(src);

    cout  << endl << "------------" << endl;+


    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(3, 2);
    g3.addEdge(3, 1);
    g3.addEdge(2, 4);
    src = g3.findSource();
    g3.printEulerPath(src);

    cout  << endl << "------------" << endl;

    return 0;
}
