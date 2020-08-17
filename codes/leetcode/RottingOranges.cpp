#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
private:
    bool visited[100][100];
    int level[100][100];
    void bfs(pair<int, int> source, vector<vector<int>> grid){
        queue<pair<int, int> > q;

        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                visited[row][col] = false;
            }
        }

        q.push(source);
        level[source.first][source.second] = 0;
        visited[source.first][source.second] = true;

        while(!q.empty()){
            pair<int, int> current = q.front();
            q.pop();
            
            int row = current.first;
            int col = current.second;
            grid[row][col] = 2;
            visited[row][col] = true;

            if(row-1>=0 && grid[row-1][col]==1 && !visited[row-1][col]){
                level[row-1][col] = min(level[row-1][col], level[row][col]+1);
                q.push(make_pair(row-1, col));
            }
            if(row+1<grid.size() && grid[row+1][col]==1 && !visited[row+1][col]){
                level[row+1][col] = min(level[row+1][col], level[row][col]+1);
                q.push(make_pair(row+1, col));
            }
            if(col-1>=0 && grid[row][col-1]==1 && !visited[row][col-1]){
                level[row][col-1] = min(level[row][col-1], level[row][col]+1);
                q.push(make_pair(row, col-1));                
            }
            if(col+1<grid[row].size() && grid[row][col+1]==1 && !visited[row][col+1]){
                level[row][col+1] = min(level[row][col+1], level[row][col]+1);
                q.push(make_pair(row, col+1));                
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int answer = -1, isThereAnyFresh=0, isThereAnyRotten = 0;
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                visited[row][col] = false;
                level[row][col] = 100000;
            }
        }
        
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                if(grid[row][col]==2){
                    isThereAnyRotten = 1;
                    bfs(make_pair(row, col), grid);
                } else if(grid[row][col]==1){
                    isThereAnyFresh = -1;
                }
            }
        }
        
        if(isThereAnyRotten == 0 || isThereAnyFresh == 0) return isThereAnyFresh;
 
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                if(grid[row][col]==1 && level[row][col]>=100000)
                    return -1;
                if(grid[row][col]==1 && level[row][col]>answer)
                    answer = level[row][col];
            }
        }
        
        return answer;
    }
};