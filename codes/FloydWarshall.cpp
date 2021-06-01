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

#define INF INT_MAX

void floydWarshall(int n, vector<vector<int>>& distances) {
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
	int n, m, q, a, b, c;
    cin >> n >> m >> q;

    vector<vector<int>> distances(n, vector<int>(n, INF));
    for(int i=0; i<n; i++)
        distances[i][i] = 0;

    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        distances[a][b] = min(distances[a][b], c);
        distances[b][a] = min(distances[b][a], c);
    }

	floydWarshall(n, distances);

	cout<<"Shortest Distances Between Every Pair of Vertices" << endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
            cout << ((distances[i][j] == INF) ? "-1" : to_string(distances[i][j])) << "\t";
		}
		cout<<endl;
	}

	return 0;
}