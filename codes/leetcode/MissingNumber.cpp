class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, i = 1;
        for(int num : nums) x ^= num ^ i++;
        return x;
    }
};