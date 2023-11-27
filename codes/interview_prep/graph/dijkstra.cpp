#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
using namespace std;

typedef pair<int, int> iPair;

void add_edge(vector<vector<iPair>>& graph, int u, int v, int w) {
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void dijkstra(vector<vector<iPair>>& graph, int n, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(n, INT_MAX);
    
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = graph[u].begin(); i != graph[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int n = 9;
    vector<vector<iPair>> graph(n, vector<iPair>());
    
    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 7, 8);
    add_edge(graph, 1, 2, 8);
    add_edge(graph, 1, 7, 11);
    add_edge(graph, 2, 3, 7);
    add_edge(graph, 2, 8, 2);
    add_edge(graph, 2, 5, 4);
    add_edge(graph, 3, 4, 9);
    add_edge(graph, 3, 5, 14);
    add_edge(graph, 4, 5, 10);
    add_edge(graph, 5, 6, 2);
    add_edge(graph, 6, 7, 1);
    add_edge(graph, 6, 8, 6);
    add_edge(graph, 7, 8, 7);

    dijkstra(graph, n, 0);

    return 0;
}
