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
#include<stdio.h>
#include<iostream>
#include <list>
#define NIL -1
using namespace std;

list<int> adj[10010];

vector< pair<int, int> > res;
vector< pair<int, int> >::iterator it;

bool visited[10010];
int disc[10010];
int low[10010];
int parent[10010];

vector<int> pr[10010];
map<pair<int, int>, bool> mp;

void addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void dfs(int u, bool visited[], int disc[], int low[], int parent[]){
	static int time = 0;

	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i){
		int v = *i;

		if (!visited[v]){
			parent[v] = u;
			dfs(v, visited, disc, low, parent);
			low[u] = min(low[u], low[v]);

			if (low[v] > disc[u]){
                res.push_back(make_pair(u, v));
                mp[make_pair(u, v)] = false;
                mp[make_pair(v, u)] = false;
			}
		}
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void findBridges(int n){
	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			dfs(i, visited, disc, low, parent);
}

void initialize(int n){
	for (int i = 0; i < n; i++){
        adj[i].clear();
        disc[i]=0;
        low[i]=NIL;
		parent[i] = NIL;
		pr[i].clear();
		visited[i] = false;
	}
	res.clear();
}

bool compare(const pair<int, int>&i, const pair<int, int>&j){

    if(i.first == j.first)
        return i.second < j.second;
    return i.first<j.first;
}

int main(){
    int t, cs = 0, n, u, k, v;

    cin >> t;

	while(t--){
        cin >> n;
        initialize(n);

        for(int i=0; i<n; i++){
            scanf("%d (%d)", &u, &k);
            while(k--){
                cin >> v;
                addEdge(u, v);
            }
        }

        findBridges(n);

        cout << "Case " << ++cs << ":" << endl;
        cout << res.size() << " critical links" << endl;

        for(int i = 0; i<res.size(); i++){
            pr[res[i].first].push_back(res[i].second);
            pr[res[i].second].push_back(res[i].first);
        }

        for(int i=0;i<n;i++){
            sort(pr[i].begin(), pr[i].end());
            for(int j=0; j<pr[i].size(); j++){
                if(mp[make_pair(i, pr[i][j])]==false && mp[make_pair(pr[i][j], i)]==false){
                    mp[make_pair(i, pr[i][j])]=true;
                    mp[make_pair(pr[i][j], i)]=true;
                    cout << i << " - " << pr[i][j] << endl;
                }
            }
        }
    }

	return 0;
}
