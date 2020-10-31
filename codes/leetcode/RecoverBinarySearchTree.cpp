class Solution {
private:
    void dfs(TreeNode* root, TreeNode* left, TreeNode* right, bool& swapped) {
        if(!root) return;
        else if(left && root->val<left->val) swapped = true, swap(root->val, left->val);
        else if(right && root->val>right->val) swapped = true, swap(root->val, right->val);
        
        dfs(root->left, left, root, swapped);
        dfs(root->right, root, right, swapped);
    }

public:
    void recoverTree(TreeNode* root) {
        bool swapped = true;
        while(swapped) {
            swapped = false;
            dfs(root, nullptr, nullptr, swapped);
        }
    }
};