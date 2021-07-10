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
            return;
        }            

        return topologicalOrder;
    }

    void dfs(int node, vector<bool>& visited, vector<int>& route) {
        visited[node] = true;
        route.push_back(node);
        for(int dependant : dependants[node]) {
            if(!visited[dependant])
                dfs(dependant, visited, route);
        }
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
    vector<bool> visited(n, false);
    vector<int> route, longestRoute;

    for(int node : order) {
        if(!visited[node]) {
            route.clear();
            graph.dfs(node, visited, route);
            if(route.size()>longestRoute.size())
                longestRoute = route;
        }
    }

    cout << longestRoute.size() << endl;
    for(int node : longestRoute) 
        cout << node << " ";

	return 0;
}
















#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m;
vector<set<pair<int,int>>> g;
vector<int> dist;
vector<int> par;
 
void dij()
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	dist[1] = 0;
	par[1] = -1;
 
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		if(dist[u] < d) continue;
		
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
			if(dist[v] > dist[u]+c)
			{
				dist[v] = dist[u]+c;
				pq.push({dist[v],v});
				par[v] = u;
			}
		}
 
 
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	par.resize(n+1);
	
	for(int i = 1; i <= n; ++i)
	{
		par[i] = -1;
	}
 
	g.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert({v,-1});
	}
	dij();
	if(dist[n] == 0)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	cout << 1 + dist[n]*(-1) << endl;
	vector<int> ans;
	int temp = n;
	while(temp != -1)
	{
		ans.push_back(temp);
		temp = par[temp];
	}
	reverse(ans.begin(), ans.end());
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
}