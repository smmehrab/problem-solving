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
    int c = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        
        int kthSmallestInLST = kthSmallest(root->left, k);
        if (kthSmallestInLST != 0) return kthSmallestInLST;
        
        c++;
        if (c == k) return root->val;
        
        int kthSmallestInRST = kthSmallest(root->right, k);
        return kthSmallestInRST;
    }
};