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

#define INF 0x3f3f3f3f

int bellmanFord(int source, int destination, int n, vector<vector<pair<int, int>>>& adjacents) {
    bool isNegativeCycle = false;
	vector<int> distances(n, INF);
    distances[source] = 0;
    for(int u=0, v, w; u<n; u++) {
        isNegativeCycle = true;
        for(pair<int, int> adjacent : adjacents[u]) {
            tie(v, w) = adjacent;
            if(distances[u] + w < distances[v]) {
                isNegativeCycle = false;
                distances[v] = distances[u] + w;
            }
        }
    }
    return (isNegativeCycle ? -1 : distances[n-1]);
}

int main() {
    int n, m, a, b, x, score;
    cin >> n >> m;

    vector<vector<pair<int, int>>> tunnels(n, vector<pair<int, int>>());
    for(int i=0; i<m; i++) {
        cin >> a >> b >> x;
        a--, b--, x *= -1;
        tunnels[a].push_back({b, x});
    }

    score = bellmanFord(0, n-1, n, tunnels);
    score *= -1;

    cout << score << endl;
    return 0;
}