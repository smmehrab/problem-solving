class Solution {
private:
    vector<vector<int>> allPath;
    vector<int> path;
    void solve(TreeNode* node, int sum, vector<int>& path) {
        bool hasPath = false;
        if(!node->left && !node->right && sum==node->val) {
            allPath.push_back(path);
        }
        if(node->left) {
            path.push_back(node->left->val);
            solve(node->left, sum-(node->val), path);
            path.pop_back();
        }
        if(node->right) {
            path.push_back(node->right->val);
            solve(node->right, sum-(node->val), path);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root) {
            path.push_back(root->val);
            solve(root, sum, path);
        }
        return allPath;
    }
};