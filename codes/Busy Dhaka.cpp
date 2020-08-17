#include<bits/stdc++.h>
using namespace std;

int cs=0, n, r, q, dest;
int b[300];
int u[300];
int v[300];
long long e[300];
long long minE[300];


void bellman_ford(int src){
    minE[src] = 0;
    for(int k = 1; k < n; k++){
        bool isChanged = false;
        for(int i = 1; i <= r; i++){
            if(minE[v[i]] > minE[u[i]] + e[i] && minE[u[i]] != INT_MAX){
                isChanged = true;
                minE[v[i]] = minE[u[i]] + e[i];
            }
        }
        if(!isChanged) break;
    }

    for(int i = 1; i <= r; i++)
        if(minE[v[i]] > minE[u[i]] + e[i] && minE[u[i]] != INT_MAX)
            minE[v[i]] = -INT_MIN;
}

int main(){
    while(cin >> n){
        for(int i=1; i<=n; i++){
            cin>>b[i];

            minE[i] = INT_MAX;
            e[i] = INT_MAX;
        }

        cin >> r;
        for(int i=1; i<=r; i++){
            cin>> u[i] >> v[i];
            int dif = (b[v[i]]-b[u[i]]);
            e[i] = dif*dif*dif;
        }

        bellman_ford(1);

        cout << "Set #" << ++cs << endl;
        cin >> q;
        while(q--){
            cin >> dest;
            if(minE[dest] >= 3 && minE[dest] != INT_MAX)
                cout << minE[dest] << endl;
            else
                cout << "?" << endl;
        }
    }
    return 0;
}
