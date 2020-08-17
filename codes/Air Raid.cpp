#include <iostream>
#include <vector>
using namespace std;

bool visited[100000];
vector <int> adj[100000];
int ans;

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i){
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

void initialize(int n) {
    for(int i = 0;i < n;++i)
        visited[i] = false;
    ans=0;
}

int main(){
    int t, cs=0, n, m, u, v;

    cin >> t;
    while(t--){
        cin >> n >> m;

        initialize(n);

        for(int i = 0; i<m; ++i){
            cin >> u >> v;
            adj[u-1].push_back(v-1);
        }

        for(int i = 0;i < n;++i){
            if(!visited[i]){
                dfs(i);
                ans++;
            }
        }

        cout << "Case " << ++cs << ": " << ans << endl;
    }
	return 0;
}
