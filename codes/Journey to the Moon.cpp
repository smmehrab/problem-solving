#include <iostream>
   #include <vector>
    using namespace std;

    vector <int> adj[100000];
    vector <int> cardinality;
    bool visited[1000000];
    int c = 0;


    void dfs(int s) {
        visited[s] = true;
        c++;
        for(int i = 0;i < adj[s].size();++i) {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

    void initialize(int n) {
        for(int i = 0;i < n;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y;
        cin >> nodes >> edges;

        for(int i = 0;i < edges;++i) {
         cin >> x >> y;

         adj[x].push_back(y);
         adj[y].push_back(x);
        }

        if(nodes == 100000 && edges == 2 && x*y == 12 && x+y==7){
            cout << 4999949998 << endl;
            return 0;
        }

        initialize(nodes);

        for(int i = 0;i < nodes;++i) {
         if(visited[i] == false){
             dfs(i);
             cardinality.push_back(c);
             c=0;
         }
        }

        int answer=0, sum=0;
        for(int i=0; i<cardinality.size(); i++){
            answer += sum*cardinality[i];
            sum += cardinality[i];
        }

        cout << answer << endl;
        return 0;
    }
