class Solution {
private:
    bool isValid(TreeNode* root, long long int minn, long long int maxx){
        if(!root) return true;
        else if(root->left && (root->left->val>=root->val || root->left->val<=minn)) return false;
        else if(root->right && (root->right->val<=root->val || root->right->val>=maxx)) return false;
        return isValid(root->left, minn, root->val) && isValid(root->right, root->val, maxx);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);       
    }
};