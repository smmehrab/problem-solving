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

vector <int> adj[100100];
vector <char> input[100100];

bool visited[100100];

void dfs(int s) {
    visited[s]=true;
    for(int i=0; i<adj[s].size(); i++) {
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

void initialize(int n){
    for(int i=0; i<n; i++){
        visited[i]=false;
        adj[i].clear();
        input[i].clear();
    }
}

bool sortbysec(const pair<char,int> &a, const pair<char,int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return (a.second > b.second);
}

int main() {
    int t, cs=0, n, m;
    cin >> t;

    while(t--){
        cin >> n >> m;

        vector <char> output;
        vector<pair<char, int> > ans;
        char temp;

        initialize(n*m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> temp;
                input[i].push_back(temp);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char temp = input[i][j];
                if(i!=n-1 && temp==input[i+1][j])
                    adj[(i*m)+j].push_back(((i+1)*m)+j);
                if(i!=0 && temp==input[i-1][j])
                    adj[(i*m)+j].push_back(((i-1)*m)+j);
                if(j!=m-1 && temp==input[i][j+1])
                    adj[(i*m)+j].push_back((i*m)+j+1);
                if(j!=0 && temp==input[i][j-1])
                    adj[(i*m)+j].push_back((i*m)+j-1);
            }
        }

        for(int i=0; i<n*m; i++) {
            if(!visited[i]){
                dfs(i);
                output.push_back(input[i/m][i%m]);
            }
        }

        sort(output.begin(),output.end());

        int cnt=1;
        cout << "World #" << ++cs << endl;
        for(int i=0; i<output.size();i+=cnt){
            cnt = count(output.begin(), output.end(), output[i]);
            ans.push_back(make_pair(output[i], cnt));
        }

        sort(ans.begin(),ans.end(),sortbysec);

        for(int i=0; i<ans.size();i++)
            cout << ans[i].first << ": " << ans[i].second << endl;
    }
    return 0;
}
