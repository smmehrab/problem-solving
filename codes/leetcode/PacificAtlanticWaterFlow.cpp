/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
private:
    int n, m;
    vector<vector<int>> heights;
    vector<vector<int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(int x, int y, int previousHeight, vector<vector<bool>>& visited) {
        if(x<0 || x>=n || y<0 || y>=m)
            return;
        
        if(visited[x][y] || heights[x][y] < previousHeight)
            return;
        
        visited[x][y] = true;
        for(vector<int> direction : directions) 
            dfs(x+direction[0], y+direction[1], heights[x][y], visited);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty())
            return {};
        
        this->heights = heights;
        this->n = heights.size();
        this->m = heights[0].size();

        vector<vector<int>> validCoordinates;
        vector<vector<bool>> pVisited(n, vector<bool>(m));
        vector<vector<bool>> aVisited(n, vector<bool>(m));
        
        for(int x = 0; x<n; x++) {
            dfs(x, 0, 0, pVisited); 
            dfs(x, m-1, 0, aVisited); 
        }

        for(int y = 0; y<m; y++) {
            dfs(0, y, 0, pVisited); 
            dfs(n-1, y, 0, aVisited);
        }
        
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                if(pVisited[x][y] && aVisited[x][y])
                    validCoordinates.push_back({x, y});
            }
        }
        
        return validCoordinates;
    }
};