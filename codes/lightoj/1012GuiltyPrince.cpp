#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool visited[900000];
list<int> *adj;

int t, cs = 0, w, h, src, ans;
char a[30][30];

void dfs(int src){
	visited[src] = true;
	ans++;

	list<int>::iterator i;
	for (i = adj[src].begin(); i != adj[src].end(); ++i)
		if (!visited[*i])
			dfs(*i);
}

void takeInput(){
    cin >> w >> h;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> a[i][j];
            if(a[i][j]=='@')
                src = (i*w)+j;
        }
    }
}

void initialize(){
    for(int i=0; i<(w*h); i++)
        visited[i] = false;
    ans=0;
	adj = new list<int>[h*w+10];
}

void createGraph(){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(a[i][j]=='.' || a[i][j]=='@'){
                int k=j+1;
                if(a[i][k]=='.' && j+1<w){
                    adj[(i*w)+k].push_back((i*w)+j);
                    adj[(i*w)+j].push_back((i*w)+k);
                }

                k=j-1;
                if(a[i][k]=='.' && j>0){
                    adj[(i*w)+k].push_back((i*w)+j);
                    adj[(i*w)+j].push_back((i*w)+k);
                }

                k=i+1;
                if(a[k][j]=='.' && i+1<h){
                    adj[(k*w)+j].push_back((i*w)+j);
                    adj[(i*w)+j].push_back((k*w)+j);
                }

                k=i-1;
                if(a[k][j]=='.' && i>0){
                    adj[(k*w)+j].push_back((i*w)+j);
                    adj[(i*w)+j].push_back((k*w)+j);
                }
            }
        }
    }
}

int main(){

    cin >> t;

    while(t--){
        takeInput();

        initialize();
        createGraph();

        dfs(src);
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}
