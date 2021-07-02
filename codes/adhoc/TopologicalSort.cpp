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
using namespace std;

class Graph {
private:
	int n;
    vector<vector<int>> dependants;
    vector<int> topologicalOrder;

	void helper(int node, vector<bool>& visited, stack<int>& sorted) {
        visited[node] = true;
        for(int dependant : dependants[node]) {
            if(!visited[dependant])
                helper(dependant, visited, sorted);
        }
        sorted.push(node);
    }

    bool checkForCycle(stack<int>& sorted) {
        map<int, int> indexOf;
        int index = 0;
    
        while(!sorted.empty()) {
            indexOf[sorted.top()] = index;
            topologicalOrder.push_back(sorted.top());
            index++;
            sorted.pop();
        }
    
        for(int i=0; i<n; i++) {
            for(int dependant : dependants[i]) {
                if(indexOf[i] > indexOf[dependant]) 
                    return true;
            }
        }
    
        return false;
    }

public:
	Graph(int n) {
	    this->n = n;
	    this->dependants = vector<vector<int>>(n, vector<int>());
    }

	void addDependant(int a, int b) {
	    dependants[a].push_back(b);
    }

	vector<int> topologicalSort() {
        stack<int> sorted;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {
            if(!visited[i])
                helper(i, visited, sorted);
        }

        if(checkForCycle(sorted)) {
            cout << "IMPOSSIBLE" << endl;
            return vector<int>();
        }            

        return topologicalOrder;
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;

	Graph graph(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        graph.addDependant(a-1, b-1);
    }    

	vector<int> order = graph.topologicalSort();
    for(int node : order) 
        cout << node << " ";

	return 0;
}