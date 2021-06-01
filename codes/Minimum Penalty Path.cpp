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
#include<limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
using namespace std;

vector<vector<pair<int,int> > > adj(1100);
int src, dest, minimumPenalty = INT_MAX;

bitset<1100> visited;
int dp[9000][9000];

void dfs(int currentNode, int currentWeight){
    if(currentNode==dest){
        minimumPenalty = min(minimumPenalty, currentWeight);
        return;
    }

    for(int i=0;i<adj[currentNode].size();i++){
        int nextNode = adj[currentNode][i].first;
        int nextWeight = adj[currentNode][i].second;
        int orWeight = nextWeight|currentWeight;

        if((visited[nextNode])||(orWeight>=minimumPenalty)||dp[nextNode][orWeight])
            continue;
        else {
            visited[nextNode]=1;
            dp[nextNode][orWeight]=1;
            dfs(nextNode, currentWeight|nextWeight);
            visited[nextNode]=0;
        }
    }
}

int main(){
    int n, e, u, v, w;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    cin>>src>>dest;

    visited[src]=1;
    dfs(src,0);

    if(minimumPenalty==INT_MAX)
        minimumPenalty = -1;

    cout<<minimumPenalty<<endl;
}
