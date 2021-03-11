#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[100000];
int level[100000];
vector<int>adj[100000];

int bfs(int s){
	queue<int>q;
	int c = 0;

	visited[s] = true;
	level[s] = 0;

    q.push(s);

	while(!q.empty()){
		int p = q.front();
		q.pop();

		for(int i=0;i < adj[p].size();i++){
			if(!visited[adj[p][i]]){
				visited[adj[p][i]] = true;
				level[adj[p][i]] = level[p] + 1;
				q.push(adj[p][i]);
            }
			else if(visited[adj[p][i]]){
				if(level[adj[p][i]]==level[p]){
					c = 1;
					return c;
				}
            }
        }
    }

    return c;
}

void initialize(int n){
    for(int i=0;i<n;i++){
        visited[i] = false;
        level[i] = 0;
    }
}


int main(){
	int n, e, u, v, c=0;
	cin >> n >> e;

	for(int i=0;i<e;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
    }

    initialize(n);

	for(int i=0;i<n;i++){
        if(!visited[i]){
            c = bfs(i);
            if(c)
                break;
        }
    }

    if(!c) cout << "No" << endl;
    else cout << "Yes" << endl;

	return 0;
}
