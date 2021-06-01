/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> graph[105];
bool visited[105];
stack <int> ans;

void dfs(int n) {
    visited[n]=true;

    for(int i=0; i<graph[n].size(); i++) {
        if(!visited[graph[n][i]])
            dfs(graph[n][i]);
    }

    ans.push(n);
}

int main() {
    int n,m;
    cin >> n >> m;

    while(m--) {
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i])
            dfs(i);
    }

    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
}
