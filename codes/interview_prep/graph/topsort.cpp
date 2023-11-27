#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* This program demonstrates the working of Topological Sort.
 * Topological Sort only works for a directed acyclic graph.
 * I have implemented this algorithm with the help of BFS.
 * Therefore, the overall time complexity is simply O(|V| + |E|)
 */

const int n = 6;
int source;
vector <bool> visited(n, false);
vector <int> indegrees(n, 0);
vector <int> result;

void add_edge(vector<int> graph[], int u, int v){
  graph[u].push_back(v);
}

void topsort(vector <int> graph[]){

    // indegrees
    for (int i = 0; i < n; i++)
        for (int neighbor : graph[i])
            indegrees[neighbor]++;

    // source
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            source = i;
            break;
        }
    }

    // algorithm
    int node;
    queue <int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
}

int main (void){
  vector<int> graph[n];
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 3);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 2, 5);
  add_edge(graph, 3, 4);
  add_edge(graph, 3, 5);
  add_edge(graph, 4, 5);
  topsort(graph);

  cout << "Topological Sort for the given DAG: ";
  for (int i = 0; i < result.size(); i++)
    cout << result.at(i) << " ";
  cout << endl;
  //Should Print: 0 1 2 3 4 5

}