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
    void dfs(TreeNode* root, TreeNode* left, TreeNode* right, bool& swapped) {
        if(!root) return;
        else if(left && root->val<left->val) swapped = true, swap(root->val, left->val);
        else if(right && root->val>right->val) swapped = true, swap(root->val, right->val);
        
        dfs(root->left, left, root, swapped);
        dfs(root->right, root, right, swapped);
    }

public:
    void recoverTree(TreeNode* root) {
        bool swapped = true;
        while(swapped) {
            swapped = false;
            dfs(root, nullptr, nullptr, swapped);
        }
    }
};