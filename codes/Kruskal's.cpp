#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int parent[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize(){
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union1(int x, int y){
    int xRoot = root(x);
    int yRoot = root(y);
    parent[xRoot] = parent[yRoot];
}

long long kruskal(pair<long long, pair<int, int> > p[]){
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y)){
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main(){
    int x, y;
    long long weight, cost, minimumCost;

    initialize();
    cin >> nodes >> edges;

    for(int i = 0;i < edges;++i){
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }

    sort(p, p + edges);
    minimumCost = kruskal(p);

    cout << minimumCost << endl;
    return 0;
}
