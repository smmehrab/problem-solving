#include <bits/stdc++.h>
#include <map>
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
    for (int i=finalPath.size()-1; i>=0; i--) {
        cout << finalPath[i];
        if (i)
           cout<<" -> ";
    }
}

int main(){
	vector< vector<int> > adj;

	adj.resize(3);

	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	printEuler(adj);

	return 0;
}

