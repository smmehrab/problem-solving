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

void dfs(int people, vector<vector<int>>& neighbors, vector<int>& moneys, long long int *groupMoney, int *groupPopulation) {
    *groupMoney += moneys[people];
    (*groupPopulation)++;
    moneys[people] = -1;
    for(int neighbor : neighbors[people]) {
        if(moneys[neighbor] != -1)
            dfs(neighbor, neighbors, moneys, groupMoney, groupPopulation);
    }
}

int main() {
    int testCaseCount;
    int n, m, u, v;
    bool equalizing;
    long long int groupMoney, totalMoney;
    int totalAverage, groupPopulation;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> m;

        vector<vector<int>> neighbors;   
        for(int i=0; i<n; i++) 
            neighbors.push_back(vector<int>());
        vector<int> moneys(n);

        totalMoney = 0;
        for(int &money : moneys) {
            cin >> money;
            totalMoney += money;
        }

        totalAverage = totalMoney/n; 
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            neighbors[u-1].push_back(v-1);
            neighbors[v-1].push_back(u-1);
        }

        equalizing = true;
        for(int i=0; i<n && equalizing; i++) {
            if(i==0 || moneys[i]!=-1) {
                groupMoney = 0;
                groupPopulation = 0;
                dfs(i, neighbors, moneys, &groupMoney, &groupPopulation);
                equalizing = (groupPopulation!=0) && ((groupMoney%groupPopulation == 0) && (groupMoney/groupPopulation == totalAverage));
            }
        }

        cout << "Case " << testCase << ": " << (equalizing ? "Yes" : "No") << endl;
    }

    return 0;
}