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
    TreeNode* dfs(vector<int>& preorder, int preorderStart, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if(preorderStart>preorder.size()-1 || inorderStart>inorderEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        
        int inorderRootIndex = -1;
        for(int i=inorderStart; i<=inorderEnd; i++) {
            if(inorder[i] == preorder[preorderStart]) {
                inorderRootIndex = i;
                break;
            }
        }
        
        int leftSubtree = inorderRootIndex-inorderStart;
        root->left = dfs(preorder, preorderStart+1, inorder, inorderStart, inorderRootIndex-1);
        root->right = dfs(preorder, leftSubtree+preorderStart+1, inorder, inorderRootIndex+1, inorderEnd);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return dfs(preorder, 0, inorder, 0, n-1);
    }
};