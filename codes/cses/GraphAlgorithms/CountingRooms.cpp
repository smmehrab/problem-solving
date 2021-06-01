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

const int MAX = 1e3 + 10;

int n, m;
string row;
bool visited[MAX][MAX];

void dfs(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m) {
        visited[x][y] = true;
        if(!visited[x-1][y])
            dfs(x-1, y);
        if(!visited[x+1][y])
            dfs(x+1, y);
        if(!visited[x][y-1])
            dfs(x, y-1);
        if(!visited[x][y+1])
            dfs(x, y+1);
    }
}

int main() {
    cin >> n >> m;
    for (int i=0, j; i<n; i++) {
        cin >> row;
        for(int j=0; j<m; j++) 
            visited[i][j] = (row[j] == '.') ? false : true;
    }

    int numberOfRooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                numberOfRooms++;
            }
        }
    }

    cout << numberOfRooms << endl;
    return 0;
}