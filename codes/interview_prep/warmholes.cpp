#include<iostream>
#include<climits>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<string>
using namespace std;

string get_point(int x, int y) {
    return to_string(x)+to_string(y);
}

int get_cost(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    
    int t, n, sx, sy, dx, dy, px, py, qx, qy, c;
    cin>>t;
    while(t--){
        cin>>n;
        map<string, vector<pair<string, int>>> graph;
        cin>>sx>>sy>>dx>>dy;
        string source = get_point(sx, sy);
        string dest = get_point(dx, dy);
        graph[source].push_back({dest, get_cost(sx, sy, dx, dy)});
        graph[dest].push_back({source, get_cost(dx, dy, sx, sy)});
        set<pair<string, vector<int>>> points;
        for(int i=0;i<n;i++){
            cin>>px>>py>>qx>>qy>>c; 
            string start = get_point(px, py);
            string end = get_point(qx, qy);
            for(auto point: points) {
                int p1x = point.second[0], p1y = point.second[1];
                graph[start].push_back({point.first, get_cost(px, py, p1x, p1y)});
                graph[point.first].push_back({start, get_cost(px, py, p1x, p1y)});
                graph[end].push_back({point.first, get_cost(qx, qy, p1x, p1y)});
                graph[point.first].push_back({end, get_cost(qx, qy, p1x, p1y)});
            }
            points.insert({start, {px, py}});
            points.insert({end, {qx, qy}});
            graph[start].push_back({end, c});
            graph[end].push_back({start, c});
            graph[source].push_back({start, get_cost(sx, sy, px, py)});
            graph[start].push_back({dest, get_cost(px, py, dx, dy)});
            graph[source].push_back({end, get_cost(sx, sy, qx, qy)});
            graph[end].push_back({dest, get_cost(qx, qy, dx, dy)});
        }
        priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
        map<string, bool> visited;
        string curr = source;
        int minCost = 0;
        while(curr!=dest) {
            visited[curr] = true;
            for(int i=0;i<(int)graph[curr].size();i++) {
                int cost = graph[curr][i].second;
                string endNode = graph[curr][i].first;
                if(visited[endNode]) continue;
                pq.push({minCost + cost, endNode});
            }
            auto topNode = pq.top();
            pq.pop();
            curr = topNode.second;
            minCost = topNode.first; 
        }
        cout<<minCost<<endl;
    }
    
    
    return 0;
}