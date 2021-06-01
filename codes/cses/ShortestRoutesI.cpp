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

#define INF LLONG_MAX

void dijkstra(int source, int n, vector<pair<int, long long int>> connections[]){
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
	vector<long long int> distances(n, INF);
    vector<bool> visited(n, false);
    int a, b;
    long long int c;

	distances[source] = 0;
	pq.push({distances[source], source});
	while(!pq.empty()){
		a = pq.top().second;
		pq.pop();
        
        if(visited[a])
            continue;

        visited[a] = true;
        for(pair<int, long long int> connection : connections[a]) {
			b = connection.first;
			c = connection.second;
			if(distances[b] > distances[a] + c) {
				distances[b] = distances[a] + c;
				pq.push({distances[b], b});
			}
		}
	}

    for(long long int distance : distances) 
        cout << distance << " ";
}

int main(){
	int n, m, a, b;
    long long int c;

    cin >> n >> m;

	vector<pair<int, long long int>> connections[n];
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        connections[a-1].push_back({b-1, c});
    }

	dijkstra(0, n, connections);
	return 0;
}