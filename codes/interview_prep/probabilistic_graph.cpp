#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
vector<double> weight[105];

pair<int, double> dp[105][1005];

// returns ending node_id, highest probability for source u, given time t
pair<int, double> solve(int u, int t) {
    // base
    if (t < 10) return {u, 1};
    // dp
    if (dp[u][t].first) return dp[u][t];

    // recur
    double ans = 0;
    int end_node = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        auto v = adj[u][i];
        auto w = weight[u][i];
        auto sol = solve(v, t - 10);
        if (ans < sol.second * w) {
        ans = sol.second * w;
        end_node = sol.first;
        }
    }

    return dp[u][t] = {end_node, ans};
}

int main() {
    int n, e, t;
    cin >> n >> e >> t;
    for (int i = 0; i < e; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        weight[u].push_back(w);
    }
    auto sol = solve(1, t);
    cout << sol.first << " " << sol.second << endl;
}

// Sample Input:
// 5 7 30
// 1 2 0.7
// 1 3 0.3
// 2 3 0.6
// 2 4 0.4
// 3 4 1
// 4 4 0.5
// 4 5 0.5