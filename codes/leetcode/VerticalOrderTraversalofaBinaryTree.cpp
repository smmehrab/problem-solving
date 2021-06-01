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
    void dfs(TreeNode* node, int x, int y, map<pair<int,int>, vector<int>>& coordinateNode) {
        coordinateNode[make_pair(x, y)].push_back(node->val);
        if(node->left) dfs(node->left, x-1, y+1, coordinateNode);
        if(node->right) dfs(node->right, x+1, y+1, coordinateNode);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> reports;        
        map<pair<int,int>, vector<int>> coordinateNode;
        
        dfs(root, 0, 0, coordinateNode);
        
        int maxCoordinateSoFar = INT_MIN;
        for(auto [coordinate, nodes] : coordinateNode) {
            auto [x, y] = coordinate;
            if(x > maxCoordinateSoFar) {
                reports.push_back(vector<int>());
                maxCoordinateSoFar = x;
            }
			
			if(nodes.size() > 1) sort(nodes.begin(), nodes.end());
            for(int node : nodes) reports.back().push_back(node);
        }
        return reports;
    }
};