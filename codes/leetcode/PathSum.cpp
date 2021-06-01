/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
private:
    bool solve(TreeNode* node, int sum) {
        bool hasPath = false;
        hasPath = (!node->left && !node->right) ? (sum==node->val) : hasPath;
        hasPath = (node->left) ? hasPath || solve(node->left, sum-(node->val)) : hasPath;
        hasPath = (node->right) ? hasPath || solve(node->right, sum-(node->val)) : hasPath;
        return hasPath;
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return solve(root, sum);
    }
};