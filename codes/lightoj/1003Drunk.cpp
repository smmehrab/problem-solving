#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int visited[100000];
int level[100000];
vector<int>adj[100000];

bool dfs(int s){
   visited[s] = GRAY;

    for (int i = 0; i < adj[s].size(); ++i){
        int temp = adj[s][i];
        if (visited[temp] == GRAY)
          return true;
        if (visited[temp] == WHITE && dfs(temp))
          return true;
    }

    visited[s] = BLACK;
    return false;
}

void initialize(int n){
    for(int i=0;i<n;i++){
        adj[i].clear();
        visited[i] = WHITE;
    }
}

int main(){
    int t, cs = 0, m, key;
    bool status;
    string a, b, res;

    cin >> t;

    while(t--){
        cin >> m;

        map<string, int> mp;

        res = "Yes";
        key = 0;
        status = false;

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            if(mp.find(a)==mp.end())
                mp[a]=key++;
            if(mp.find(b)==mp.end())
                mp[b]=key++;

            adj[mp[a]].push_back(mp[b]);
            for(int i = 0; i<adj[mp[b]].size();i++){
                if(adj[mp[b]][i]==mp[a])
                    status=1;
            }

        }

        initialize(key);

        for(int i=0;i<key;i++){
            if(visited[i] == WHITE && !status){
                status = dfs(i);
                if(status)
                    break;
            }
        }

        if(status)
            res = "No";

        cout << "Case " << ++cs << ": " << res << endl;
    }
	return 0;
}
