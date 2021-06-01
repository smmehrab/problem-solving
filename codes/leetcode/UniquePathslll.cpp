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
    
    class Cell{
    private:
        int x, y;
    public:
        Cell(int x, int y){
            this->x = x;
            this->y = y;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }
    };

    int numberOfPaths=0, width, height;
    void findPaths(Cell cell, vector<vector<int>>grid, int nthCell, int validCellCount){        
        int x = cell.getX();
        int y = cell.getY();

        if(x>=width || y>=height || x<0 || y<0 || grid[x][y]==-1){           
            return;
        }
        
        if(grid[x][y]==2 && nthCell==validCellCount){
            numberOfPaths++;
            return;
        }
         
        grid[x][y]=-1;
        findPaths(Cell(x, y+1), grid, nthCell+1, validCellCount);
        findPaths(Cell(x+1, y), grid, nthCell+1, validCellCount);
        findPaths(Cell(x, y-1), grid, nthCell+1, validCellCount);
        findPaths(Cell(x-1, y), grid, nthCell+1, validCellCount);
        grid[x][y]=0;
    }
    
public:

    int uniquePathsIII(vector<vector<int>>& grid) {
        width = grid.size();
        height = grid[0].size();

        Cell startingCell(-1, -1);
        int validCellCount=0;

        for(int x=0; x<width; x++){
            for(int y=0; y<height; y++){
                if(grid[x][y]==1) startingCell = Cell(x, y);
                if(grid[x][y]!=-1) validCellCount++;
            }
        }
        
        findPaths(startingCell, grid, 1, validCellCount);
        return numberOfPaths;
    }
};