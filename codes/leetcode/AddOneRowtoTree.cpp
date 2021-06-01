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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        TreeNode* node;
        TreeNode* left;
        TreeNode* right;
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;
        while (level < d-1) {
            int levelNodesCount = q.size();
            while(levelNodesCount--) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);                
            }
            level++;
        }
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            left = node->left;
            right = node->right;
            
            node->left = new TreeNode(v);
            node->left->left = left;
            
            node->right = new TreeNode(v);
            node->right->right = right;
        }
        
        return root;
    }
};