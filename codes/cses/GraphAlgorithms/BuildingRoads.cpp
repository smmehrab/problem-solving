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

void dfs(int i, vector<int> adjacents[], vector<bool>& visited) {
    visited[i] = true;
    for(int adjacent : adjacents[i]) {
        if(!visited[adjacent])
            dfs(adjacent, adjacents, visited);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> adjacents[n];
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adjacents[a-1].push_back(b-1);
        adjacents[b-1].push_back(a-1);    
    }
    
    vector<bool> visited(n, false);
    vector<int> disconnecteds;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            disconnecteds.push_back(i);
            dfs(i, adjacents, visited);    
        }
    }

    cout << disconnecteds.size()-1 << endl;
    a = disconnecteds[0]+1;
    for(int i=1; i<disconnecteds.size(); i++) {
        b = disconnecteds[i]+1;
        cout << a << " " << b << endl;
        a = b;
    }

	return 0;
}