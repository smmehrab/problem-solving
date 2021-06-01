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
#include <map>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;


void printEuler(vector< vector<int> > adj){
    stack<int> currentPath;
	vector<int> finalPath;
	map<int,int> edgeCount;
    int currentVertex;
    int nextVertex;

	for (int i=0; i<adj.size(); i++)
		edgeCount[i] = adj[i].size();

	if (!adj.size())
		return;

	currentPath.push(0);
	currentVertex = 0;

	while (!currentPath.empty()){
		if (edgeCount[currentVertex]!=0){
			currentPath.push(currentVertex);
			// Returning the last adjacent vertex of current vertex
			nextVertex = adj[currentVertex].back();
            // Removing edge to that adjacent vertex
			edgeCount[currentVertex]--;
			adj[currentVertex].pop_back();
            // Leaving the current vertex
			currentVertex = nextVertex;
		}
		else{
			finalPath.push_back(currentVertex); // Done with this vertex

			currentVertex = currentPath.top(); // Choosing another one from the current path
			currentPath.pop(); // Removing that, as we are going to work that now
		}
	}

	int previous = -1;
	for (int i=finalPath.size()-1; i>=0; i--){
        if(previous!=-1 && previous!=finalPath[i])
            cout << previous+1 << " " << finalPath[i]+1 << endl;
        previous = finalPath[i];
	}
}

int main(){
    int  n, m, u, v, src, cs=0;
    while(true){
        cin >> n >> m;
        if(n==0 && m==0)
            break;

        vector< vector<int> > adj;
        adj.resize(n);

        for(int i=0; i<m; i++){
            cin >> u >> v;
            adj[u-1].push_back(v-1);
        }

        cout << ++cs << endl;
        cout << endl;
        printEuler(adj);
        cout << "#" << endl;
    }
    return 0;
}
