/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
#include<limits.h>
using namespace std;

const int d = 10007;
int V, E, u, v, q;
int dist[200][200];

void floydWarshall (){
	for (int k = 1; k <= V; k++){
		for (int i = 1; i <= V; i++){
			for (int j = 1; j <= V; j++){
				dist[i][j] = (((dist[i][k]%d)*(dist[k][j]%d)) + (dist[i][j]%d)) % d;
			}
		}
	}
}

int main(){
    cin >> V >> E;

    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            dist[i][j]=0;

    for(int i=0; i<E; i++){
        cin >> u >> v;
        dist[u][v]=1;
    }

	floydWarshall();

	cin >> q;
	while(q--){
        cin >> u >> v;
        cout << dist[u][v] << endl;
	}

	return 0;
}

