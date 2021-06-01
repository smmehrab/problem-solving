/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include <list>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include<map>
using namespace std;

list< pair<int, int> > edges[100100];
bool visited[100100];

int maximum[100100];
int secondMaximum[100100];
int ans;

void addEdge(int u, int v, int w){
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
}

void refresh(int n){
    ans = 0;
    for(int i = 0; i < n; i++){
        edges[i].clear();
        maximum[i]=0;
        secondMaximum[i]=0;
        visited[i] = false;
    }
}

void readEdges(int n, int u, int v, int w){
    for(int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
}

int findMaxPath(int s){
    int w;
	visited[s] = true;

	list<pair<int, int> >::iterator i;
	for(i=edges[s].begin(); i!=edges[s].end(); i++){
		if(!visited[i->first]){
			w = i->second;
			w += findMaxPath(i->first);

			if(w>=maximum[s]){
				secondMaximum[s] = maximum[s];
				maximum[s] = w;
			}
			else if(w>secondMaximum[s])
				secondMaximum[s] = w;
		}
	}

	ans = max(maximum[s] + secondMaximum[s], ans);
	return maximum[s];
}

void output(int cs){
    findMaxPath(0);
    cout << "Case " << cs << ": " << ans  << endl;
}

int main(){
    int t, cs=0, n, u, v, w;
    cin >> t;
    while(t--){
        cin >> n;
        refresh(n);
        readEdges(n, u, v, w);
        output(++cs);
    }
	return 0;
}

