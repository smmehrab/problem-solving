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
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

bool visited[900000];
vector<int>adj[900000];
int level[900000];
vector<int>index[900000];

int p, len, w;

int n, m, d, src, b, c, mx;
char a[600][600];

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
				visited[w] = true;
				level[w] = level[p] + 1;
				q.push(w);
            }
        }
    }
}

findSource(){
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]!='#')
                src=(i*m)+j;
        }
    }
}

void createGraph(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]=='.'){
                int k=j+1;
                if(a[i][k]=='.' && j<m-1){
                    adj[(i*m)+k].push_back((i*m)+j);
                    adj[(i*m)+j].push_back((i*m)+k);
                }

                k=j-1;
                if(a[i][k]=='.' && j){
                    adj[(i*m)+k].push_back((i*m)+j);
                    adj[(i*m)+j].push_back((i*m)+k);
                }

                k=i+1;
                if(a[k][j]=='.' && i<n-1){
                    adj[(k*m)+j].push_back((i*m)+j);
                    adj[(i*m)+j].push_back((k*m)+j);
                }

                k=i-1;
                if(a[k][j]=='.' && i){
                    adj[(k*m)+j].push_back((i*m)+j);
                    adj[(i*m)+j].push_back((k*m)+j);
                }
            }
        }
    }
}

void takeInput(){
    cin >> n >> m >> d;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin >> a[i][j];
    }
}

void initialize(){
    for(int i=0; i<(n*m); i++){
        visited[i] = false;
        level[i] = -1;
    }
}

int main(){

    takeInput();
    if(d!=0){
        initialize();
        createGraph();
        findSource();
        bfs(src);
        mx=0;
        for(int i =0; i<(n*m); i++){
            if(level[i]!=-1){
                index[level[i]].push_back(i);
                if(mx<level[i])
                    mx=level[i];
            }
        }

        for(int i = mx; i>=0 && d!=0; i--){
            for(int j = 0; j<index[i].size() && d!=0; j++){
                b=index[i][j];
                a[b/m][b%m] = 'X';
                d--;
            }
        }
    }

    for(int i =0;i<n;i++){
        for(int j = 0; j<m;j++)
            cout << a[i][j];
        cout << endl;
    }

    return 0;
}
