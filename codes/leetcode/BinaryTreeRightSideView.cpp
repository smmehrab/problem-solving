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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        
        if (!root) 
            return rightNodes;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nodesInLevel = q.size();
            for (int i=0; i<nodesInLevel; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) 
                    q.push(node->left);
                if (node->right) 
                    q.push(node->right);
                if (i==nodesInLevel-1) 
                    rightNodes.push_back(node->val);
            }
        }
        
        return rightNodes;
    }
};