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
    int numberOfNodes, postorderIndex;
    vector<int> inorder, postorder;
    unordered_map<int, int> nodeInorderIndex;
    
    TreeNode *buildUtil(int start, int end){
        if(start > end) return nullptr;
        
        TreeNode *root = new TreeNode(postorder.at(postorderIndex--));
        int inorderIndex   = nodeInorderIndex.at(root->val);
        root->right = buildUtil(inorderIndex+1, end);
        root->left  = buildUtil(start, inorderIndex-1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        numberOfNodes = postorder.size();
        postorderIndex = numberOfNodes - 1;
        this->inorder = inorder;
        this->postorder = postorder;
        for(int i=0; i<numberOfNodes; i++) nodeInorderIndex.insert({inorder[i], i});
        return buildUtil(0, numberOfNodes-1);
    }
};