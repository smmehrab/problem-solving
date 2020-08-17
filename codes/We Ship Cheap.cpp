#include<bits/stdc++.h>
using namespace std;

map<string,string> route;
map <string,int> visited;


void findroutes(string d, string s){
  if(d==s)
    return;
  findroutes(route[d], s);
  cout << route[d] << " " << d << endl;;
}


int bfs(string s, string d, map<string,vector<string> > adj){
  queue<string>q;

  q.push(s);
  visited[s]=1;

  while(!q.empty()){
    string top = q.front();
    q.pop();

    if(top == d)
      return visited[top];

    int len = adj[top].size();

    for(int i=0; i<len; i++){
        string temp = adj[top][i];
        if(visited[temp]==-1){
            visited[temp]=visited[top]+1;
            route[temp]=top;
            q.push(temp);
        }
    }
  }

  return -1;
}

int main(){
  int links;
  bool c = false;

  while(cin >> links){
    map<string,vector<string> > adj;
    string city1,city2,src,dest;

    for (int i = 0; i < links; ++i){
        cin>>city1>>city2;

        adj[city1].push_back(city2);
        adj[city2].push_back(city1);

        visited[city1]=-1;
        visited[city2]=-1;
    }

    cin>>src>>dest;

    if(c)
        cout << endl;

    c = true;

    if(bfs(src, dest, adj)!=-1)
        findroutes(dest,src);

    else
      cout << "No route" << endl;
  }
  return 0;
}
