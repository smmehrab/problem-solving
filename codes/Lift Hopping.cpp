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

int  n, src=0, dest;
int dist[101];
vector <pair<int, int> > adj[101];
vector<int> stopages[101];

int dijkstra(int src, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int u, v, t;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while( !pq.empty()){
        u = pq.top().second;
        pq.pop();

        if(dest==u)
            return dist[dest];

        for(int i=0; i <adj[u].size(); ++i){
            v = adj[u][i].first;
            t = adj[u][i].second+60;

            if(dist[v] > dist[u] + t){
                dist[v] = dist[u] + t;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[dest];
}

void refresh(){
    for(int i=0; i<100; ++i){
        adj[i].clear();
        stopages[i].clear();
        dist[i] = INF;
    }
}

int main(){
    int  stopage, current, next, ans;
    int T[10];
    string line;

    while(scanf("%d %d", &n, &dest) == 2){
        refresh();

        for(int i=0; i<n; i++)
            cin >> T[i];

        getline(cin, line);
        for(int i=0; i<n; i++){
            getline(cin, line);
            stringstream ss(line);

            while(ss >> stopage)
                stopages[i].push_back(stopage);

            for(int j=0; j<stopages[i].size(); j++){
                current = stopages[i][j];
                for(int k=j+1; k<stopages[i].size(); k++){
                    next = stopages[i][k];
                    adj[current].push_back(make_pair(next, (next-current)*T[i]));
                    adj[next].push_back(make_pair(current, (next-current)*T[i]));
                }
            }
        }

        ans = dijkstra(src, dest);

        if(ans==INF)
            puts("IMPOSSIBLE");
        else{
            if(dest!=0)
                ans -= 60;
            cout << ans << endl;
        }
    }
    return 0;
}
