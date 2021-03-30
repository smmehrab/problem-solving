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
    int vIndex = 0;
    
    void dfs(TreeNode* root, vector<int>& voyage, vector<int>& flipped) {
        if (!root || (!flipped.empty() && flipped[0] == -1) || vIndex>=voyage.size()) 
            return;
        else if (root->val != voyage[vIndex++]) 
            flipped = {-1};
        else if (root->left && root->left->val != voyage[vIndex]) {
            flipped.push_back(root->val);
            dfs(root->right, voyage, flipped);
            dfs(root->left, voyage, flipped);
        } 
        else {
            dfs(root->left, voyage, flipped);
            dfs(root->right, voyage, flipped);
        }
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flipped;
        dfs(root, voyage, flipped);
        return flipped;
    }
};