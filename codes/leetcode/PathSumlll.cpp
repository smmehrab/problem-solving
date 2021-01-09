class Solution {
private:
    int solve(TreeNode* root, int sum, int targetSum, unordered_map<int, int>& dp) {
        if(!root) return 0;

        sum += root->val;
        int ret = dp[sum-targetSum];
        dp[sum]++;
        ret += solve(root->left, sum, targetSum, dp);
        ret += solve(root->right, sum, targetSum, dp);
        dp[sum]--;
        
        return ret;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        return solve(root, 0, targetSum, dp);;
    }
};