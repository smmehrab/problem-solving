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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        if (!node->left && !node->right) return {node->val, 0};
                
        pair<int, int> leftSum = dfs(node->left);
        pair<int, int> rightSum = dfs(node->right);
        
        int withNode = node->val + leftSum.second + rightSum.second;
        int withoutNode = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);
        return {withNode, withoutNode};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> sum = dfs(root);
        return max(sum.first, sum.second);
    }
};