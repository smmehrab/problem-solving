class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        result[0].push_back(1);
        result.push_back(vector<int>());
        result[1].push_back(1);
        result[1].push_back(1);
        for(int row=2; row<=rowIndex; row++){
            result.push_back(vector<int>());
            for(int col = 0; col<=row; col++){
                if(col == 0)
                    result[row].push_back(1);
                else if(col == row)
                    result[row].push_back(1);
                else
                    result[row].push_back(result[row-1][col-1]+result[row-1][col]);    
            }
        }
        
        return result[rowIndex];
    }
};