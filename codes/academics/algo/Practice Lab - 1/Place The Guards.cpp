#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, e;
    cin >> t;
    while ( t-- ){
        cin >> n >> e;

        vector<vector<int> > v(n);
        vector<int> color(n, -1);

        bool isBipartite = true;

        while ( e-- ){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int c = 0;
        for (int i = 0; i < v.size() && isBipartite; ++i){
            if (color[i] != -1)
                continue;

            queue<int> q;
            int count[2] = {0};
            color[i] = 0;

            ++count[color[i]];
            q.push(i);

            while (!q.empty() && isBipartite){
                int a = q.front();
                q.pop();
                for (int j = 0; j < v[a].size(); ++j)
                {
                    int b = v[a][j];
                    if (color[b] == color[a]){
                        isBipartite = false;
                        break;
                    }
                    else if (color[b] == -1){
                        color[b] = 1 - color[a];
                        ++count[color[b]];
                        q.push(b);
                    }
                }
            }
            c += max(1, min(count[0], count[1]));
        }

        if (isBipartite)
            cout << c << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
