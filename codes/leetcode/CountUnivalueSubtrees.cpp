class Solution {
private: 
    int count;
    bool isUnivalueSubtree(TreeNode* node) {
        if (!node) return true;
        int leftSubtree = isUnivalueSubtree(node->left);
        int rightSubtree = isUnivalueSubtree(node->right);
        if (leftSubtree && rightSubtree) {
            if (node->left && node->left->val != node->val) return false; 
            if (node->right && node->right->val != node->val) return false; 
            count++;
            return true;
        }
        return false;
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        bool temp = isUnivalueSubtree(root);
        return count;
    }
};