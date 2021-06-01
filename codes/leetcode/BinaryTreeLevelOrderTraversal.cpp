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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if (!root) 
            return traversal;
        
        deque<TreeNode*> q;
        vector<int> level;
        int nodesInLevel;
        
        q.push_back(root);
        while (!q.empty()) {
            nodesInLevel = q.size();
            level.clear();
            
            for (int i=0; i<nodesInLevel; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                
                level.push_back(node->val);
                
                if(node->left) 
                    q.push_back(node->left);
                if(node->right) 
                    q.push_back(node->right);
            }
            
            traversal.push_back(level);
        }
        
        return traversal;
    }
};