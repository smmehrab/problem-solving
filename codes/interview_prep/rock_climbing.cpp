#include <iostream>
using namespace std;

int n, m;
int map[10][10], visited[10][10];
int min_difficulty = 11;
int from, to, jump;

void climb_rock(int i, int j, int max_jump) {
    if((i >= n || i < 0) || (j >= m || j < 0))
        return;
    else if(map[i][j] == 0 || visited[i][j] == 1)
        return;
    // goal
    else if(map[i][j] == 3) {
        if(max_jump < min_difficulty)
            min_difficulty = max_jump;
        return;
    } 

    visited[i][j] = 1;

    // move up
    from = i;
    to = i+1;
    jump = 0;
    while(to != n && map[to][j] == 0)
        to++;
    if(to != n && visited[to][j] == 0 && map[to][j] != 0) {
        jump = to - from;
        if(max_jump > jump)
            jump = max_jump;
        climb_rock(to, j, jump);
    }

    // move down
    from = i;
    to = i-1;
    jump = 0;
    while(to != -1 && map[to][j] == 0)
        to--;
    if(to != -1 && visited[to][j] == 0 && map[to][j] != 0) {
        jump = from - to;
        if(max_jump > jump)
            jump = max_jump;
        climb_rock(to, j, jump);
    }

    // move right
    if((j>=0&&j<m) && (map[i][j+1] == 1 || map[i][j+1] == 3) && (visited[i][j+1] == 0)) {
        climb_rock(i, j+1, max_jump);
    }

    // move left
    if((j>=0&&j<m) && (map[i][j-1] == 1 || map[i][j-1] == 3) && (visited[i][j-1] == 0)) {
        climb_rock(i, j-1, max_jump);
    }

    visited[i][j] = 0;
}

int main() {
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            cin >> map[i][j];
    }
    climb_rock(n-1, 0, 0);
    cout << min_difficulty << endl;
    return 0;
}