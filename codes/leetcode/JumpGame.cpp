class Solution {
public:
    bool canJump(vector<int>& nums) {
        int valid = nums.size()-1;
        for (int i=valid; i>=0; i--) valid = (i+nums[i] >= valid) ? i : valid;
        return valid == 0;
    }
};