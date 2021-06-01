/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector <int> adj[100100];
bool visited[100100];

void dfs(int s) {
    visited[s] = true;
    for(int i=0; i<adj[s].size(); ++i){
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

void topSort(int s, stack<int>& Stack) {
    visited[s] = true;
    for(int i=0; i<adj[s].size(); ++i){
        if(!visited[adj[s][i]])
            topSort(adj[s][i], Stack);
    }
    Stack.push(s);
}

int main() {
    int t, n, e, x, y, connectedComponents;
    cin >> t;
    while(t--){
        cin >> n >> e;
        stack<int> Stack;

        for(int i=0; i<n; ++i){
            visited[i] = false;
            adj[i].clear();
        }

        for(int i=0; i<e; ++i) {
            cin >> x >> y;
            adj[x-1].push_back(y-1);
        }

        for(int i=0; i<n; ++i){
            if(!visited[i])
                topSort(i, Stack);
        }

        for(int i=0; i<n; ++i)
            visited[i] = false;

        connectedComponents = 0;
        while (!Stack.empty()){
            int j = Stack.top();
            Stack.pop();

            if(!visited[j]){
                dfs(j);
                connectedComponents++;
            }
        }

        cout << connectedComponents << endl;
    }
    return 0;
}
