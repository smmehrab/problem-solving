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
    int n;
    vector<vector<int>> graph;
    vector<int> color;
    
    void initializeColors(int n) {
        for(int i=0; i<n; i++) 
            color.push_back(-1);
    }

    bool dfs(int index, int adjacentColor){
        color[index] = 1-adjacentColor;
        bool status = true;
        for(int adjacent : graph[index]){
            if(color[adjacent]==-1) status = dfs(adjacent, color[index]);
            else if(color[adjacent]==color[index]) status = false;
            if(!status) break;
        }
        return status;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->graph = graph;
        initializeColors(n);
        
        bool status = true;
        for(int index=0; index<n; index++) {
            if(color[index]==-1) {
                status = dfs(index, 0); 
                if(!status) break;
            }
        }
        return status;
    }
};