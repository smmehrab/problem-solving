#include<bits/stdc++.h>
using namespace std;

int r, c;
vector<string> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> directions {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

struct Node {
    int x, y, t;
    Node() : x(0), y(0), t(0) {}
    Node(int X, int Y, int T) : x(X), y(Y), t(T) {}
};

bool isOnBoundary(Node node) {
    return (node.x == r-1 || node.y == c-1 || node.x == 0 || node.y == 0);
}

bool isOutOfBound(Node node) {
    return (node.x < 0 || node.y < 0 || node.x >= r || node.y >= c);
}

void updateGrid() {
    vector<string> updatedGrid = grid;
    Node adjacent;

    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            if(grid[x][y] == 'F') {
                for(pair<int, int> direction : directions) {
                    adjacent = Node(x+direction.first, y+direction.second, 0);
                    if(!isOutOfBound(adjacent) && updatedGrid[adjacent.x][adjacent.y] == '.')
                        updatedGrid[adjacent.x][adjacent.y] = 'F';
                }
            }
        }
    }
    grid = updatedGrid;
}

int bfs(Node source) {
    int time;
    queue<Node> q;
    Node node, adjacent;

    time = source.t;
    visited[source.x][source.y] = true;
    q.push(source);
    while(!q.empty()) {
        node = q.front();
        q.pop();
        
        if(node.t == time) {
            updateGrid();
            time++;
        }

        if(isOnBoundary(node))
            return node.t+1;

        for(pair<int, int> direction : directions) {
            adjacent = Node(node.x+direction.first, node.y+direction.second, node.t+1);            
            if(!isOutOfBound(adjacent) && grid[adjacent.x][adjacent.y] == '.' && !visited[adjacent.x][adjacent.y]) {
                visited[adjacent.x][adjacent.y] = true;
                q.push(adjacent);
            }
        }
    }

    return -1;
}

void refresh() {
    grid = vector<string>(r);
    visited = vector<vector<bool>>(r, vector<bool>(c, false));
}

int main() {
    int testCaseCount, timeToEscape;
    Node source;
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> r >> c;
        refresh();

        for(string &row : grid) 
            cin >> row;

        for(int x=0; x<r; x++) {
            for (int y=0; y<c; y++) {
                if (grid[x][y] == 'J')
                    source = Node(x, y, 0);
            }
        }

        timeToEscape = bfs(source);
        cout << "Case " << testCase << ": " << (timeToEscape==-1 ? "IMPOSSIBLE" : to_string(timeToEscape)) << endl;
    }
    return 0;
}