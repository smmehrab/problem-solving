class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int subArrayLen = n+1;
        for (int i=0, left=0, sum=0; i<n; i++) {
            sum += nums[i];
            while (sum >= target) {
                subArrayLen = min(subArrayLen, i-left+1);
                sum -= nums[left++];
            }
        }
        return (subArrayLen != n+1) ? subArrayLen : 0;
    }
};