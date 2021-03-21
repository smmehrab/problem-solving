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
    void morrisTraversal(TreeNode* root, vector<int> &traversal) {
        TreeNode *current, *predecessor;

        if (!root)
            return;

        current = root;
        while (current) {
            if (!current->left) {
                traversal.push_back(current->val);
                current = current->right;
            }
            else {
                predecessor = current->left;
                while (predecessor->right && predecessor->right != current)
                    predecessor = predecessor->right;

                if (!predecessor->right) {
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    predecessor->right = nullptr;
                    traversal.push_back(current->val);
                    current = current->right;
                } 
            } 
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        morrisTraversal(root, traversal);
        return traversal;
    }
};