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
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;
vector< vector<int> > v;
bool visited[110];

void inaccessible(int i){
    fill(visited, visited+n, false);

    queue<int> q;
    q.push(i);

    int tmp;

    while(!q.empty()){
        tmp = q.front();
        q.pop();

        for(int j=0; j < v[tmp].size(); ++j){
            if(visited [ v[tmp][j] ] )
                continue;

            visited[ v[tmp][j] ] = true;
            q.push(v[tmp][j]);
        }
    }

    int c=0;

    for(int j=0; j<n; ++j){
        if(!visited[j])
            c++;
    }

    cout << c;

    for(int j=0; j<n; ++j){
        if(!visited[j])
            cout << " " << j+1;
    }
    cout << endl;
}

int main(){
    int x, y, q;

    while(1){
        cin >> n;
        if(n==0) break;

        v.clear();
        v.resize(n);

        while(1){
            cin >> x;
            if(x==0)
                break;

            while(1){
                cin >> y;
                if(y==0)
                    break;

                v[x-1].push_back(y-1);
            }
        }

        cin >> q;

        for(int i=0; i<q; ++i){
            cin >> x;
            inaccessible(x-1);
        }
    }

    return 0;
}
