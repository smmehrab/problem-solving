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

#define N 1003

string path, moves = "DURL";
int parent[N][N];
vector<pair<int, int>> directions {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool isOnBoundary(pair<int, int> a, int n, int m) {
    return (a.first == n-1 || a.second == m-1 || a.first == 0 || a.second == 0);
}

bool isOutOfBound(pair<int, int> a, int n, int m) {
    return (a.first < 0 || a.second < 0 || a.first >= n || a.second >= m);
}

bool bfs(vector<string>& grid, int n, int m) {
    int x, y, nx, ny, previousMove;
    queue<pair<int,int>> q;
    pair<int, int> current;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 'M')
                q.push({i, j});
            else if (grid[i][j] == 'A')
                current = {i, j};
        }
    }
    
    q.push(current);
    parent[current.first][current.second] = -1;
    while(!q.empty()) {
        current = q.front();
        x = current.first;
        y = current.second;
        q.pop();

        if(isOnBoundary({x, y}, n, m) && grid[x][y] == 'A') {
            path = "";
            previousMove = parent[x][y];
            while(previousMove != -1) {
                path += moves[previousMove];
                x -= directions[previousMove].first;
                y -= directions[previousMove].second;
                previousMove = parent[x][y];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        int index = 0;
        for(pair<int, int> direction : directions) {
            nx = x + direction.first; 
            ny = y + direction.second;
            if(!isOutOfBound({nx, ny}, n, m) && grid[nx][ny] == '.') {
                grid[nx][ny] = grid[x][y];
                if(grid[nx][ny] == 'A') 
                    parent[nx][ny] = index;
                q.push({nx,ny});
            }
            index++;
        }
    }

    return false;
}

int main(){
    int n, m; 
    cin >> n >> m;

    vector<string> grid(n);
    for (string &row : grid)
        cin >> row;

    bool isPossible = bfs(grid, n, m);

    cout<< (isPossible ? "YES" : "NO") << endl;
    if(isPossible) {
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;
}