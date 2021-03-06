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
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        bool unival = true;
        if(root->left) unival &= (root->val == root->left->val);
        if(root->right) unival &= (root->val == root->right->val);
        return unival && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};