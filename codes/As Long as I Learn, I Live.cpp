/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[100000];
vector<int>adj[100000];
int maxChild[100000];
int value[100000];
int p, len, w, maxGain, lastNode;

void dfs(int s){
    visited[s]=true;
    maxGain += value[s];
    if(maxChild[s]!=-1)
        dfs(maxChild[s]);
    else
        lastNode = s;
}

void initialize(int n){
    for(int i=0; i<n; i++){
        visited[i] = false;
        adj[i].clear();
        maxChild[i]=-1;
    }
    maxGain=0;
    lastNode=0;
}

int main(){
    int t, cs=0, n, m, u, v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        initialize(n);

        for(int i=0; i<n; i++)
            cin >> value[i];

        for(int i=0; i<m; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            if(maxChild[u]==-1)
                maxChild[u]=v;
            else if(value[v]>value[maxChild[u]])
                maxChild[u]=v;
            else if(value[v]==value[maxChild[u]] && v>maxChild[u])
                maxChild[u]=v;
        }

        dfs(0);


        cout << "Case " << ++cs << ": " << maxGain << " " << lastNode << endl;
    }
    return 0;
}
