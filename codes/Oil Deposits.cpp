/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[100100];
bool visited[100100];

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i){
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

void initialize(int n) {
    for(int i=0; i<n; ++i){
        visited[i] = false;
        adj[i].clear();
    }
}

int main(){
    int row, column, ans;
    while(true){
        cin >> row >> column;
        if(row == 0)
            break;

        ans = 0;
        initialize(row*column);
        char sign[row][column];

        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cin >> sign[i][j];
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(sign[i][j]=='@'){
                    if(i!=row-1 && sign[i+1][j]=='@'){
                        adj[(i*column)+j].push_back(((i+1)*column)+j);
                        adj[((i+1)*column)+j].push_back((i*column)+j);
                    }

                    if(i!=row-1 && j!=0 && sign[i+1][j-1]=='@'){
                        adj[(i*column)+j].push_back(((i+1)*column)+j-1);
                        adj[((i+1)*column)+j-1].push_back((i*column)+j);
                    }

                    if(i!=row-1 && j!=column-1 && sign[i+1][j+1]=='@'){
                        adj[(i*column)+j].push_back(((i+1)*column)+j+1);
                        adj[((i+1)*column)+j+1].push_back((i*column)+j);
                    }

                    if(j!=column-1 && sign[i][j+1]=='@'){
                        adj[(i*column)+j].push_back((i*column)+j+1);
                        adj[(i*column)+j+1].push_back((i*column)+j);
                    }
                }
            }
        }

        for(int i=0; i<(row*column); i++){
            if(!visited[i] && sign[(i/column)][i%column]=='@'){
                dfs(i);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
