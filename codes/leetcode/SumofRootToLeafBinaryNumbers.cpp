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
    int traverse(TreeNode* node, int sum) { 
        if (!node) return 0;
        sum <<= 1;
        sum += node->val;
        return (!node->left && !node->right) ? sum : traverse(node->left, sum) + traverse(node->right, sum);
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        return traverse(root, 0);
    }
};