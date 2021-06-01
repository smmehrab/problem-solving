#include<bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX

void floydWarshall(int n, vector<vector<long long int>>& distances) {
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(distances[i][k] != INF && distances[k][j] != INF && distances[i][k] + distances[k][j] < distances[i][j])
					distances[i][j] = distances[i][k] + distances[k][j];
			}
		}
	}
}

int main(){
	int n, m, q, a, b;
    long long int c;

    cin >> n >> m >> q;
    vector<vector<long long int>> distances(n, vector<long long int>(n, INF));
    for(int i=0; i<n; i++)
        distances[i][i] = 0;

    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        distances[a][b] = min(distances[a][b], c);
        distances[b][a] = min(distances[b][a], c);
    }

	floydWarshall(n, distances);

	for(int i=0; i<q; i++) {
        cin >> a >> b;
        a--; b--;
        cout << ((distances[a][b] == INF) ? "-1" : to_string(distances[a][b])) << endl;
    }

	return 0;
}