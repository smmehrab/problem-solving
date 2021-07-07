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

# define INF DBL_MAX

void addEdge(vector<pair<int, double> > adj[], int u, int v, double w){
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void shortestPath(vector<pair<int, double> > adj[], int n){
	priority_queue<pair<double, int>, vector< pair< double, int > > > pq;
    vector<double> dist(n, INF);
	vector<bool> visited(n, false);

	for(int i=0; i<n; i++)
        dist[i] = INF;

	pq.push(make_pair(1.00, 0));
	dist[0] = 1.00;

	while (!pq.empty()){
		int u = pq.top().second;
		visited[u] = true;
		pq.pop();

		//cout << u+1 << endl;

		vector<pair<int, double> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i){
			int v = (*i).first;
			double weight = (*i).second;

			if ((dist[v] < (dist[u] * weight) || dist[v] == INF) && !visited[v]){
				dist[v] = dist[u]*weight;
				//cout << u+1 <<  " " << v+1 << " " << dist[v] << endl;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	/*
    printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
    */

    dist[n-1] *= 100;
    printf("%0.6lf percent\n", dist[n-1]);
}

int main(){
	int t, n, e, u, v;
    double w;

    while(cin >> n && n!=0){
        cin >> e;

        vector<pair<int, double> > adj[n];

        for(int i=0; i<e; i++){
            cin >> u >> v >> w;
            w = w*1.00/100.00;
            addEdge(adj, u-1, v-1, w);
        }

        shortestPath(adj, n);
    }
	return 0;
}
