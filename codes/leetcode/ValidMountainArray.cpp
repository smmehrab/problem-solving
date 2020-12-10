class Solution {
public:
    bool validMountainArray(vector<int>& heights) {
        int n = heights.size();
        if(n<3) return false;
        
        bool increasing = true;
        for(int i=0; i<n-1; i++) {
            if(increasing) {
                if(heights[i]<heights[i+1]) continue;
                else if(heights[i]>heights[i+1] && i!=0) increasing = false;
                else return false;
            }
            else {
                if(heights[i]>heights[i+1]) continue;
                else return false;
            }
        }
        
        return !increasing;
    }
};