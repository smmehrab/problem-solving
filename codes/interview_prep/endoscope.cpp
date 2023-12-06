#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int grid[50][50], n, m, R, C, L;
int visited[50][50] = {0};

void backtrack(int x, int y, int l){
    if(x<0 || x>=n || y<0 || y>=m || l==0)
        return;
    // cout << "x: " << x << " y: " << y << " l: " << l << endl;
    visited[x][y] = 1;
    // up-down-left-right
    if(grid[x][y] == 1) {
        // up
        if((x!=0) && (grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6 || grid[x-1][y] ==1))
            backtrack(x-1, y, l-1);
        // down
        if((x!=n-1) && (grid[x+1][y] ==2 || grid[x+1][y] ==4 || grid[x+1][y] ==7 || grid[x+1][y] ==1))
            backtrack(x+1, y, l-1);
        // left
        if((y!=0)&& (grid[x][y-1] ==3 || grid[x][y-1] ==4 || grid[x][y-1] ==5 || grid[x][y-1] ==1))
            backtrack(x, y-1, l-1);
        // right
        if((y!=m-1) && (grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7 || grid[x][y+1] ==1))
            backtrack(x, y+1, l-1);
    }
    // up-down
    else if(grid[x][y] == 2) {
        // up
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==5 || grid[x-1][y] ==6 || grid[x-1][y] ==2))
            backtrack(x-1, y, l-1);
        // down
        if((x!=n-1) && (grid[x+1][y] ==1 || grid[x+1][y] ==4 || grid[x+1][y] ==7 || grid[x+1][y] ==2))
            backtrack(x+1, y, l-1);
    }
    // left-right
    else if(grid[x][y] == 3) {
        // left
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==4 || grid[x][y-1] ==5 || grid[x][y-1] ==3))
            backtrack(x, y-1, l-1);
        // right
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==6 || grid[x][y+1] ==7 || grid[x][y+1] ==3))
            backtrack(x, y+1, l-1);
    }
    // up-right
    else if(grid[x][y] == 4) {
        // up
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6))
            backtrack(x-1, y, l-1);
        // right
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7))
            backtrack(x, y+1, l-1);
    }
    // down-right
    else if(grid[x][y] == 5) {
        // down
        if((x!=n-1) && (grid[x+1][y] =1 || grid[x+1][y] ==2 || grid[x+1][y] ==7 || grid[x+1][y] ==4))
            backtrack(x+1, y, l-1);
        // right
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7))
            backtrack(x, y+1, l-1);
    }
    // down-left
    else if(grid[x][y] == 6) {
        // down
        if((x!=n-1) && (grid[x+1][y] ==1 || grid[x+1][y] ==2 || grid[x+1][y] ==7 || grid[x+1][y] ==4))
            backtrack(x+1, y, l-1);
        // left
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==3 || grid[x][y-1] ==5 || grid[x][y-1] ==4))
            backtrack(x, y-1, l-1);
    }
    // up-left
    else if(grid[x][y] == 7) {
        // up
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6))
            backtrack(x-1, y, l-1);
        // left
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==3 || grid[x][y-1] ==4 || grid[x][y-1] ==5))
            backtrack(x, y-1, l-1);
    }
}


int main() {
    int testcases;
    cin >> testcases;
    while(testcases--){
        cin>>n>>m>>R>>C>>L;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                cin>>grid[i][j];
        }

        backtrack(R,C,L);

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1) {
                    count++;
                    visited[i][j]=0;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}