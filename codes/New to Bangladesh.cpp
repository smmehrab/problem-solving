/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define ll long long

vector<int> adj[200];
ll dist[200], tim[200];
ll dd[200][200];
ll tt[200][200];

void dijkstra(ll src){
    ll u, v, i, c, a;

    priority_queue< pair< ll, ll >, vector< pair< ll, ll > >, greater<pair<ll,ll > > > q;

    q.push(make_pair(0, src));
    dist[src] = 0;
    tim[src]=0;

    while(!q.empty()){
        u = q.top().second;
        c = q.top().first;
        q.pop();

        for(i = 0; i < adj[u].size(); i++){
            v = adj[u][i];

            if(tim[v] > tim[u] + tt[u][v]){
                tim[v] = tim[u] + tt[u][v];
                dist[v] = dist[u] + dd[u][v];
                q.push(make_pair(tim[v],v));
            }

            else if(tim[v] == tim[u] + tt[u][v] && dist[v] > dist[u] + dd[u][v]){
                tim[v] = tim[u] + tt[u][v];
                dist[v] = dist[u] + dd[u][v];
                q.push(make_pair(tim[v],v));
            }
        }
    }
}

void reset(){
    for(int i=0;i<200;i++){
        dist[i]=INF;
        tim[i]=INF;
        for(int j=0; j<200; j++){
            dd[i][j] = dd[j][i] = INF;
            tt[i][j] = dd[j][i] = INF;
        }
    }
}

void smallReset(){
    for(int i=0;i<200;i++){
        dist[i]=INF;
        tim[i]=INF;
    }
}

int main(){
    int t,n,m,q;
    ll u,v,a,w;

    cin >> t;

    while(t--){
        cin >> n >> m;
        reset();

        for(int i=1;i<=m;i++){
            cin >> u >> v >> a >> w;
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(a<tt[u][v] || (a==tt[u][v] && w<dd[u][v])){
                dd[u][v] = dd[v][u] = w;
                tt[u][v] = tt[v][u] = a;
            }
        }

        cin >> q;
        while(q--){
            smallReset();
            cin >> u >> v;
            dijkstra(u);
            if(tim[v]==INF || dist[v]==INF)
                cout << "No Path." << endl;
            else
                cout << "Distance and time to reach destination is " << dist[v] << " & " << tim[v] << "." << endl;
        }

        if(t) puts("");
    }
    return 0;
}
