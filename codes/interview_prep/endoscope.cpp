#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int grid[50][50], n, m, R, C, L;
int visited[50][50]={0};

void dfs(int x, int y, int l){
    if(x<0 || x>=n || y<0 || y>=m || l==0)
        return;
    visited[x][y]=1;
    if(grid[x][y] == 1){
        if((x!=0) && (grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6 || grid[x-1][y] ==1))  //up
            dfs(x-1, y, l-1);
        if((x!=n-1) && (grid[x+1][y] ==2 || grid[x+1][y] ==4 || grid[x+1][y] ==7 || grid[x+1][y] ==1)) //down
            dfs(x+1, y, l-1);

        if((y!=0)&& (grid[x][y-1] ==3 || grid[x][y-1] ==4 || grid[x][y-1] ==5 || grid[x][y-1] ==1))     //left
            dfs(x, y-1, l-1);
        if((y!=m-1) && (grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7 || grid[x][y+1] ==1))   //right
            dfs(x, y+1, l-1);
        
    }
    else if(grid[x][y] == 2){
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==5 || grid[x-1][y] ==6 || grid[x-1][y] ==2))    //up
            dfs(x-1, y, l-1);
        if((x!=n-1) && (grid[x+1][y] ==1 || grid[x+1][y] ==4 || grid[x+1][y] ==7 || grid[x+1][y] ==2))  //down
            dfs(x+1, y, l-1);
        
    }
    else if(grid[x][y] == 3){
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==4 || grid[x][y-1] ==5 || grid[x][y-1] ==3))     //left
            dfs(x, y-1, l-1);
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==6 || grid[x][y+1] ==7 || grid[x][y+1] ==3))   //right
            dfs(x, y+1, l-1);
        
    }
    else if(grid[x][y] == 4){
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6))    //up
            dfs(x-1, y, l-1);  
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7))   //right
            dfs(x, y+1, l-1);
        
    }
    else if(grid[x][y] == 5){
        if((x!=n-1) && (grid[x+1][y] =1 || grid[x+1][y] ==2 || grid[x+1][y] ==7 || grid[x+1][y] ==4))  //down
            dfs(x+1, y, l-1);
        if((y!=m-1) && (grid[x][y+1] ==1 || grid[x][y+1] ==3 || grid[x][y+1] ==6 || grid[x][y+1] ==7))   //right
            dfs(x, y+1, l-1);
        
    }
    else if(grid[x][y] == 6){
        if((x!=n-1) && (grid[x+1][y] ==1 || grid[x+1][y] ==2 || grid[x+1][y] ==7 || grid[x+1][y] ==4))  //down
            dfs(x+1, y, l-1);
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==3 || grid[x][y-1] ==5 || grid[x][y-1] ==4))     //left
            dfs(x, y-1, l-1);
        
    }
    else if(grid[x][y] == 7){
        if((x!=0) && (grid[x-1][y] ==1 || grid[x-1][y] ==2 || grid[x-1][y] ==5 || grid[x-1][y] ==6))    //up
            dfs(x-1, y, l-1);
        if((y!=0)&& (grid[x][y-1] ==1 || grid[x][y-1] ==3 || grid[x][y-1] ==4 || grid[x][y-1] ==5))     //left
            dfs(x, y-1, l-1);
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

        dfs(R,C,L);

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