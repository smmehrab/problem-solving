#include<bits/stdc++.h>
#include<iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;

bool visited[100000];
vector<int>adj[100000];
int level[100000];
int height[100000];

int p, len, w, res = 0;

void bfs(int s){
	queue<int>q;
	visited[s] = true;
    level[s] = 0;
    q.push(s);

	while(!q.empty()){
		p = q.front();
        q.pop();
		len = adj[p].size();

		for(int i=0; i < len; i++){
			w = adj[p][i];
			if(!visited[w]){
                level[w] = level[p] + 1;
				visited[w] = true;
				q.push(w);
            }
        }
    }
}

void initializeVis(int n){
    for(int i=0; i<n; i++)
        visited[i] = false;
}

void initializeLev(int n){
    for(int i=0; i<n; i++)
        level[i] = 0;
}

int findMaxLevel(int n){
    int c = 0;
    for(int i=0; i<n-1; i++){
        if(level[i]>c)
            c=level[i];
    }

    return c;
}

int main(){
	int n, u, v;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    initializeVis(n);
    initializeLev(n);

    for(int i=0; i<n; i++){
        if(!visited[i])
            bfs(i);
    }

    int maxLevel = findMaxLevel(n);

    res = (2*(n-1)) - maxLevel;
    cout << res << endl;
	return 0;
}
