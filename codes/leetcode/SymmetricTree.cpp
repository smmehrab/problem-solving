/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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
    bool mirror(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2) 
            return ((root1->val == root2->val) && mirror(root1->left, root2->right) && mirror(root1->right, root2->left));
        return (!root1 && !root2);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return mirror(root, root);
    }
};