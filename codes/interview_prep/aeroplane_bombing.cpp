#include <iostream>
using namespace std;

int testcases;
int n;
int grid[15][5];
int max_coins = 0;
int dx[] = {-1, -1, -1};
int dy[] = {-1, 0, 1};

void play(int x, int y, int coin, bool bomb_used, int safe_row) {
    if (x == 0) {
        if (coin > max_coins) 
            max_coins = coin;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < 5) {
            if (grid[nx][ny] == 1) {
                if (safe_row > 0)
                    safe_row -= 1;
                play(nx, ny, coin + 1, bomb_used, safe_row);
            }
            else if (grid[nx][ny] == 0) {
                if (safe_row > 0)
                    play(nx, ny, coin, bomb_used, safe_row - 1);
                else
                    play(nx, ny, coin, bomb_used, safe_row);
            } 
            else if (grid[nx][ny] == 2) {
                if (bomb_used == false)
                    play(nx, ny, coin, true, 5);
                else if (safe_row > 0)
                    play(nx, ny, coin, bomb_used, safe_row - 1);
                else continue;
            }
        }
    }
}

int main() {
    cin >> testcases;
    for (int t = 1; t <= testcases; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }
        max_coins = 0;
        play(n, 2, 0, false, 0);
        cout << "#" << t << " " << max_coins << endl; 
    }
    return 0;
}