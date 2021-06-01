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

vector<pair<int, int>> directions {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},    
};

int main() { 
    int n, m, x, y, newX, newY;
    char step;
    string path;
    queue<pair<int, int>> q;
    pair<int, int> source, destination, current;
    map<pair<int, int>, pair<pair<int, int>, char>> parent;

    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                source = {i, j};
        }
    }

    visited[source.first][source.second] = true;
    q.push(source);
    while (!q.empty()) {
        current = q.front();
        q.pop();

        x = current.first; 
        y = current.second;
        for(pair<int, int> direction : directions) {
            newX = x + direction.first;
            newY = y + direction.second;
            if(newX>=0 && newX<n && newY>=0 && newY<m) {
                if(!visited[newX][newY] && (grid[newX][newY] == '.' || grid[newX][newY] == 'B')) {
                    if(direction.first == 1 && direction.second == 0)
                        step = 'D';
                    else if(direction.first == -1 && direction.second == 0)
                        step = 'U';
                    else if(direction.second == 1 && direction.first == 0)
                        step = 'R';
                    else
                        step = 'L';

                    parent[{newX, newY}] = {{x, y}, step};

                    if(grid[newX][newY] == 'B'){
                        current = {newX, newY};
                        path = "";
                        do {
                            path += parent[current].second;
                            current = parent[current].first;
                        } while(!(current.first == source.first && current.second == source.second));
                        reverse(path.begin(), path.end()); 

                        cout << "YES" << endl;
                        cout << path.size() << endl;
                        cout << path << endl; 
                        goto exit;
                    }

                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }   
        }
    }

    cout << "NO" << endl;

exit:
    return 0;
}