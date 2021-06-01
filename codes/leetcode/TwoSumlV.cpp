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
    bool findPair(TreeNode* root, int k, set<int> &nodes) {
        if (!root) return false;
        
        // Searching Left Subtree
        if (findPair(root->left, k, nodes)) return true;
        
        // Processing Current Node
        if (nodes.find(k-root->val) != nodes.end()) return true;
        else nodes.insert(root->val); 

        // Searching Right Subtree
        return findPair(root->right, k, nodes);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> nodes;
        return findPair(root, k, nodes);
    }
};