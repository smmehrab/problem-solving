class Solution {
private:
    int helper(TreeNode* root, int sum){
        if(!root) return 0;
        int count = 0;
        if(root->val == sum) count++;
        count += helper(root->left, sum-root->val);
        count += helper(root->right, sum-root->val);
        return count;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int includingRoot = helper(root, sum);
        int excludingRoot = pathSum(root->left, sum) + pathSum(root->right, sum);
        return includingRoot + excludingRoot;
    }
};