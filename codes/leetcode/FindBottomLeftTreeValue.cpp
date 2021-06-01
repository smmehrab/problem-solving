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
    int findBottomLeftValue(TreeNode* root) {
        int nodesInLevel;
        vector<int> levelNodes;
        
        if (!root) 
            return -1;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            levelNodes.clear();
            nodesInLevel = q.size();
            for (int i=0; i<nodesInLevel; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) 
                    q.push(node->left);
                if (node->right) 
                    q.push(node->right);
                levelNodes.push_back(node->val);
            }
        }
        
        return levelNodes[0];
    }
};