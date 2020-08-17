class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;
        for(int number = 0; number < pow(2,n); number++){
            vector<int> subset;
            for(int bit=0; bit < n; bit++){
                if((number>>bit)&1){
                    subset.push_back(nums[bit]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};