#include <iostream>
#include <list>
#include <stack>
#include<vector>
#define NIL -1
using namespace std;

int res = 0;
vector<int> adj[1000];
bool visited[1000];
bool nodePair[1000];

void addEdge(int u, int v){
    adj[u].push_back(v);
}

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)
        if(!visited[adj[s][i]] && !nodePair[s])
            dfs(adj[s][i]);
}

int main(){
    int n, e, u, v;
    string str[100];


    cin >> str[0];
    n=str[0].size();
    for(int i=1; i<n; i++)
        cin >> str[i];

    for(int i=0; i<n; i++){
        visited[i]=false;
        nodePair[i]=false;
        for(int j=0; j<n; j++){
            if(str[i][j]=='Y')
                addEdge(i, j);
        }
    }

    int cnt=0, c=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }

    for(int i=0; i<n-1 ; i++){
        nodePair[i]=true;
        for(int j=i+1; j<n ; j++){
            nodePair[j]=true;

            for(int k=0; k<n; k++)
                visited[k]=false;

            c=0;
            for(int k=0; k<n; k++){
                if(!visited[k] && !nodePair[k]){
                    dfs(k);
                    c++;
                }
            }

            if(c>cnt)
                res++;

            nodePair[j]=false;
        }
        nodePair[i]=false;
    }

    cout << res << endl;
    return 0;
}
