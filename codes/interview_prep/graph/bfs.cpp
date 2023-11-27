#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void add_edge(vector <int> graph[], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector <int> graph[], vector <bool> visited, int src){
    int node;
    queue <int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()){
      node = q.front();
      q.pop();
      cout << node << " ";
      for (int neighbor : graph[node])
        if (!visited[neighbor]) {
          q.push(neighbor);
          visited[neighbor] = true;
        }
    }
    cout << endl;
}

int main (void){
    const int n = 6;
    int src = 0;
    vector<int> graph[n];
    vector <bool> visited(n, false);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 5);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 3);
    add_edge(graph, 4, 4);
    add_edge(graph, 5, 5);
    bfs(graph, visited, src); 
    // Ouput: 0 1 2 5 3 4
}