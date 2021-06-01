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
    void dfs(TreeNode* node, int level, vector<double>& levelNodesSum, vector<int>& levelNodesCount) {
        if(!node) return;
        if(levelNodesSum.size()<=level) {
            levelNodesSum.push_back(node->val);
            levelNodesCount.push_back(1);
        }
        else {
            levelNodesSum[level] += node->val;
            levelNodesCount[level]++;
        }
        
        dfs(node->left, level+1, levelNodesSum, levelNodesCount);
        dfs(node->right, level+1, levelNodesSum, levelNodesCount);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levelNodesSum, levelNodesAvg;
        vector<int> levelNodesCount;
        
        dfs(root, 0, levelNodesSum, levelNodesCount);
        
        int numberOfLevels = levelNodesSum.size();
        for(int i=0; i<numberOfLevels; i++) {
            levelNodesAvg.push_back((levelNodesSum[i]*1.0)/(levelNodesCount[i]*1.0));
        }
        
        return levelNodesAvg;  
    }
};