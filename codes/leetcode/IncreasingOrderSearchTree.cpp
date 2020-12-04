class Solution {
private:
    TreeNode* current;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        node->left = nullptr;
        current->right = node;
        current = current->right;
        inorder(node->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = new TreeNode(0);
        current = newRoot;
        inorder(root);
        newRoot = newRoot->right;
        return newRoot;
    }
};