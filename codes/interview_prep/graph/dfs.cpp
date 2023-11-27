#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void add_edge(vector<int> graph[], int u, int node){
    graph[u].push_back(node);
    graph[node].push_back(u);
}

void dfs(vector <int> graph[], vector <bool> visited, int node){
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node])
        if (!visited[neighbor])
            dfs(graph, visited, neighbor);
}

void dfs_iterative(vector <int> graph[], vector <bool> visited, int src){
    int node;
    stack <int> s;
    s.push(src);
    visited[src] = true;
    while (!s.empty()){
        node = s.top();
        s.pop();
        cout << node << " ";
        for (int neighbor : graph[node])
        if (!visited[neighbor]){
            s.push(neighbor);
            visited[neighbor] = true;
        }
    }
    cout << endl;
}

int main (void){
    const int n = 5;
    int src = 0;
    vector<int> graph[n];
    vector <bool> visited(n, false);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 3, 3);
    add_edge(graph, 4, 4);
    add_edge(graph, 2, 2);
    dfs_iterative(graph, visited, src);
    // Output: 0 2 1 4 3
    dfs(graph, visited, src);
    // Output: 0 1 3 4 2
}