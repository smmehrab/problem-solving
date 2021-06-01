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

using namespace std;

int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool vis[100011];

bool isBipartite()
{
    color[0] = 1;
    queue <int> q;
    q.push(0);

    while (!q.empty()){
        int temp = q.front();
        q.pop();

        for (i=0;i<n;i++){
            if (graph[temp][i] && color[i] == -1) {
                color[i] = 1 - color[temp];
                q.push(i);
            }
            else if (graph[temp][i] && color[i] == color[temp])
                return 0;
        }

    }

    return 1;
}

int main(){
    int x,y;
    cout<<"Enter number of vertices and edges respectively:";
    cin>>n>>e;

    cout<<"\n";

    graph.resize(n);
    color.resize(n,-1);
    memset(vis,0,sizeof(vis));

    for(i=0;i<n;i++)
        graph[i].resize(n);

    for(i=0;i<e;i++){
        cout<<"\nEnter edge vertices of edge "<<i+1<<" :";
        cin>>x>>y;

        x--;
        y--;

        graph[x][y]=1;
        graph[y][x]=1;
    }

    if(isBipartite())
        cout<<"Yes, The given graph is Bipartite.\n";
    else
        cout<<"No, The given graoh is not Bipartite.\n";

    return 0;
}
