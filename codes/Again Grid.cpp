#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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
				level[w] = level[p] + 1;
				q.push(w);
            }
        }
    }
}

void initialize(int range){
    for(int i=0; i<range; i++){
        visited[i] = false;
        level[i] = -1;
    }
}



int main(){
    int n, m;
    char a[120][120];

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin >> a[i][j];
    }

    initialize(n*m);

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

    bfs(0);

    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cout << level[(i*m)+j] << " ";
        cout << endl;
    }
    */

    cout << level[(n*m)-1] << endl;

    return 0;
}
