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
    int solve(TreeNode* node, int maxSoFar, int minSoFar) {
        if (!node) return (maxSoFar-minSoFar);
        
        maxSoFar = max(maxSoFar, node->val);
        minSoFar = min(minSoFar, node->val);
        return max(solve(node->left, maxSoFar, minSoFar), solve(node->right, maxSoFar, minSoFar));
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return (!root) ? 0 : solve(root, root->val, root->val);
    }
};