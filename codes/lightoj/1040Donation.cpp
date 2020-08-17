#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

const int MAX = 1e5 + 5;
typedef pair<long long, int> WNP; // Weight Node Pair
bool marked[MAX];
bool visited[MAX];
vector <WNP> adj[MAX];
int n, e;

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

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)    {
        if(visited[adj[s][i].second] == false)
            dfs(adj[s][i].second);
    }
}

int main(){
    int t, cs=0;
    int len, total, needed, donation, broke;

    cin >> t;

    while(t--){
        cin >> n;

        for(int i=0; i<n; ++i){
            adj[i].clear();
            marked[i] = false;
            visited[i] = false;
        }

        e = (n*n);
        total = 0;
        needed = 0;
        broke = 0;

        for(int i = 0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> len;
                total+=len;
                if(len && i!=j){
                    adj[i].push_back(make_pair(len, j));
                    adj[j].push_back(make_pair(len, i));
                }
            }
        }

        dfs(0);

        for(int i=0; i<n; i++)
            if(!visited[i])
                broke=1;


        if(broke)
            cout << "Case " << ++cs << ": " << -1 << endl;

        else{
            needed += prim(0);
            donation = total - needed;
            //cout << needed << endl;
            cout << "Case " << ++cs << ": " << donation << endl;
        }
    }
    return 0;
}
