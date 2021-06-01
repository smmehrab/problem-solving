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

#define INF INT_MAX

struct Node {
    int x, y, jumpCount;
};
typedef struct Node Node;

bool visited[12][12];
int movesRequired[110][12][12];
vector<vector<int>> directions {
    {1, 2}, 
    {1, -2}, 
    {2, 1}, 
    {2, -1}, 
    {-1, 2}, 
    {-1, -2}, 
    {-2, 1}, 
    {-2, -1}
};

void bfs(int x, int y, int rider, int jumpLimit, int n, int m) {
    int moves;
    Node node, adjacent;
    queue<Node> q;

    node.x = x;
    node.y = y;
    node.jumpCount = 0;

    q.push(node);    
    visited[node.x][node.y] = true;
    movesRequired[rider][node.x][node.y] = 0;

    while(!q.empty()) {
        node = q.front();
        q.pop();

        for(vector<int> direction : directions) {
            adjacent.x = node.x + direction[0];
            adjacent.y = node.y + direction[1];

            // Valid Jump
            if(adjacent.x>=0 && adjacent.x<n && adjacent.y>=0 && adjacent.y<m) {
                adjacent.jumpCount = node.jumpCount + 1;
                moves = (adjacent.jumpCount/jumpLimit);
                moves += (adjacent.jumpCount%jumpLimit != 0);
                if(!visited[adjacent.x][adjacent.y]) {
                    q.push(adjacent);
                    visited[adjacent.x][adjacent.y] = true;
                    movesRequired[rider][adjacent.x][adjacent.y] = moves;
                }
            }
        }
    }
}

int main() {
    int testCaseCount, n, m, riderCount, moves, minMoves;
    string row;
    
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n >> m;

        memset(movesRequired , -1, sizeof(movesRequired));
        riderCount = 0;
        for(int i=0; i<n; i++) {
            cin >> row;
            for(int j=0; j<m; j++) {
                if(row[j] != '.') {
                    memset(visited, false, sizeof(visited));
                    bfs(i, j, riderCount++, row[j]-'0', n, m);
                }
            }
        }

        minMoves = INF;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                moves = 0;
                for(int rider=0; rider<riderCount; rider++) {
                    moves += movesRequired[rider][i][j];
                    if(movesRequired[rider][i][j] == -1) {
                        moves = INF;
                        break;
                    }
                }
                minMoves = (moves<minMoves) ? moves : minMoves;
            }
        }

        minMoves = (minMoves == INF) ? -1 : minMoves;
        cout << "Case " << testCase << ": " << minMoves << endl;
    }

    return 0;
}