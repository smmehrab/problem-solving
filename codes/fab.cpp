#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<int>v[100100];
vector<int>v2[100100];

stack<int>stck;
queue<int>q;

bool visited[100100];
bool visited2[100100];


void dfs(int s){
	if(visited[s])
        return;

	visited[s]=true;
	for(int i=0;i<v[s].size();i++){
		if(!visited[v[s][i]])
            dfs(v[s][i]);
	}

	stck.push(s);
}

void dfs2(int s){
	if(visited2[s])
        return;

	visited2[s]=true;
	q.push(s);

	for(int i=0;i<v2[s].size();i++){
		if(!visited2[v2[s][i]])
			dfs2(v2[s][i]);
	}

	while(!q.empty()){
		int x=q.front();
		q.pop();

		cout << x << " ";
	}
}


int main() {
	int n,e;
	cin >> n >> e;
	int e1,e2;

	for(int i=0;i<e;i++){
		cin >> e1 >> e2;
		v[e1].push_back(e2);
	}

    for(int i=0; i<n; i++){
        visited[i]=false;
        visited2[i]=false;
	}


	for(int i=0;i<n;i++){
		if(!visited[i])
            dfs(i);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<v[i].size();j++)
			v2[v[i][j]].push_back(i);
	}

	while(!stck.empty()){
		int x=stck.top();
		stck.pop();

		if(!visited2[x]){
			dfs2(x);
            cout << endl;
		}
	}

	return 0;
}
