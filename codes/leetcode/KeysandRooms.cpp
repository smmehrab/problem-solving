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
    void dfs(int index, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[index] = true; 
        for (int adjacent : rooms[index]) 
            if (!visited[adjacent])
                dfs(adjacent, rooms, visited); 
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numberOfRooms = rooms.size();
        vector<bool> visited(numberOfRooms, false);
        dfs(0, rooms, visited);
        for(bool status : visited) {
            if(!status)
                return false;
        }
        return true;
    }
};