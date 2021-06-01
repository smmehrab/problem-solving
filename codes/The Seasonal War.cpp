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
#include <stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> adj[10010];
char input[100][100];
bool visited[10010];

void dfs(int s){
    visited[s]=true;
    for(int i=0; i<adj[s].size(); i++){
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

int main(){
    int n, m, cs=0, ans;
    while(scanf("%d", &n)==1){
        m = n;
        for(int i=0; i<(n*n); i++){
            visited[i]=false;
            adj[i].clear();
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>input[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = input[i][j];
                //cout << temp;
                if(i!=n-1 && temp==input[i+1][j])
                    adj[(i*m)+j].push_back(((i+1)*m)+j);
                if(i!=0 && temp==input[i-1][j])
                    adj[(i*m)+j].push_back(((i-1)*m)+j);
                if(j!=m-1 && temp==input[i][j+1])
                    adj[(i*m)+j].push_back((i*m)+j+1);
                if(j!=0 && temp==input[i][j-1])
                    adj[(i*m)+j].push_back((i*m)+j-1);

                if(i!=n-1 && j!=m-1 && temp==input[i+1][j+1])
                    adj[(i*m)+j].push_back(((i+1)*m)+j+1);
                if(i!=0 && j!=0 && temp==input[i-1][j-1])
                    adj[(i*m)+j].push_back(((i-1)*m)+j-1);
                if(j!=m-1 && i!=0 && temp==input[i-1][j+1])
                    adj[(i*m)+j].push_back(((i-1)*m)+j+1);
                if(j!=0 && i!=n-1 && temp==input[i+1][j-1])
                    adj[(i*m)+j].push_back(((i+1)*m)+j-1);
            }
            //cout << endl;
        }

        ans=0;
        for(int i=0; i<(n*n); i++){
            if(!visited[i] && input[i/n][i%n]=='1'){
                dfs(i);
                ans++;
            }
        }

        cout << "Image number " << ++cs <<" contains " << ans << " war eagles." << endl;
    }
    return 0;
}
