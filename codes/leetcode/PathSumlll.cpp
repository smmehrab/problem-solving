/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, int sum, int desiredSum, unordered_map<int, int>& sumCount)
    {
        if(!root) return 0;

        sum += root->val;
        int ret = sumCount[sum - desiredSum]; 

        sumCount[sum]++;
        ret += solve(root->left, sum, desiredSum, sumCount);
        ret += solve(root->right, sum, desiredSum, sumCount);
        sumCount[sum]--;
        
        return ret;
    }

public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        return solve(root, 0, sum, sumCount);;
    }
};