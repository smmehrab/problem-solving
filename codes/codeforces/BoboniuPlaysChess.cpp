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

int n, m, sx, sy;
bool visited[200][200];

void dfs(int x, int y){
    
    if(!visited[x][y]){
        visited[x][y] = true;
        cout << x+1 << " " << y+1 << endl;
    }

    int newX = (x+1)%n;
    int newY = (y+1)%m;

    if(newY<m && newY>=0 && !visited[x][newY])
        dfs(x, newY);

    if(newX<n && newX>=0 && !visited[newX][y])
        dfs(newX, y);
}

int main()
{
    cin >> n >> m >> sx >> sy;
    memset(visited, false, sizeof(visited));
    dfs(sx-1, sy-1);
    return 0;
}