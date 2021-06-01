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
    int longest;
    int findSubtreeLongest(TreeNode* node) {
        if (!node) return 0;
        
        int leftSubtreeLongest = findSubtreeLongest(node->left);
        int rightSubtreeLongest = findSubtreeLongest(node->right);
        
        int leftLongest = (node->left && node->left->val == node->val) ? leftSubtreeLongest + 1 : 0;
        int rightLongest = (node->right && node->right->val == node->val) ? rightSubtreeLongest + 1 : 0;
        
        longest = max(longest, leftLongest + rightLongest);
        return max(leftLongest, rightLongest);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        longest = 0;
        int temp = findSubtreeLongest(root);
        return longest;
    }
};