#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[100000];
vector<int>adj[100000];
int level[100000];
int p, len, w;

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
				//cout << p << " " << level[p] << endl;
				level[w] = level[p] + 6;
				q.push(w);
            }
        }
    }
}

void initialize(int n){
    for(int i=0; i<n; i++){
        visited[i] = false;
        level[i] = -1;
        adj[i].clear();
    }
}


int main(){
	int q, n, e, u, v, s;
	cin >> q;

	while(q--){
        cin >> n >> e;
        initialize(n);

        for(int i=0; i<e; i++){
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        cin >> s;

        bfs(s-1);

        for(int i=0;i<n;i++){
            if(i!=s-1){
                cout << level[i];
                if(i!=n-1)
                    cout << " ";
            }
        }

        cout << endl;
	}

	return 0;
}
