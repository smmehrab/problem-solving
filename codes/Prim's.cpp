#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
-
const int MAX = 1e5 + 5;
typedef pair<long long, int> WNP; // Weight Node Pair
bool marked[MAX];
vector <WNP> adj[MAX];

long long prim(int src){
    priority_queue<WNP, vector<WNP>, greater<WNP> > pq;

    WNP p;
    vector <WNP> res;
    int x, y;
    long long minCost = 0;

    pq.push(make_pair(0, src));

    while(!pq.empty()){
        p = pq.top();
        pq.pop();

        x = p.second;

        if(marked[x])
            continue;

        minCost += p.first;
        marked[x] = true;
        res.push_back(p);

        for(int i = 0; i < adj[x].size(); ++i){
            y = adj[x][i].second;
            if(!marked[y])
                pq.push(adj[x][i]);
        }
    }

    /*
    vector<WNP>::iterator i;
    for(i = res.begin();i!=res.end();++i)
        cout << (*i).first << " " << (*i).second << endl;
    */
    return minCost;
}

int main(){
    int n, e, x, y;
    long long w, minCost;

    cin >> n >> e;

    for(int i = 0; i < e; ++i){
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(w, y));
        adj[y].push_back(make_pair(w, x));
    }

    minCost = prim(1);
    cout << minCost << endl;
    return 0;
}
