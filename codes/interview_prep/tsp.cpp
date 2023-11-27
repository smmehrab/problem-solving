#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n, vector<vector<int>>&graph, int index, int ini_mask, int total_mask){
    if(ini_mask==total_mask){
        return graph[index][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++) {
        // not visited
        if((ini_mask & (1<<i))==0) {
            // visited
            int y = (ini_mask | (1<<i));
            // from index to i
            int temp = graph[index][i] + solve(n, graph, i, y , total_mask);
            ans = min(ans, temp);
        }
    }
    return ans;
}

int main() {
    int number_of_testcases, n, x;
    cin >> number_of_testcases;
    while(number_of_testcases--){
        cin >> n;

        vector<vector<int>> graph;
        for(int i=0;i<n;i++) {
            vector<int> row;
            for(int j=0;j<n;j++){
                cin >> x;
                row.push_back(x);
            }
            graph.push_back(row);
        }

        int ini_mask=1;
        int total_mask=(1<<n)-1;
        cout<< solve(n, graph, 0, ini_mask, total_mask) <<endl;
    }
    return 0;
}