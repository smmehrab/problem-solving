class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int previous;
        bool isFirst = true;
        for(int &num : nums) {
            if(isFirst) 
                isFirst = false;
            else {
                num += previous;   
            }
            previous = num;
        }
        return nums;
    }
};