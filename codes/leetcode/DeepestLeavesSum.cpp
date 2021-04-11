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
    int bfs(TreeNode* root) {
        int levelNodes, levelSum;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            levelNodes = q.size();
            levelSum = 0;
            while(levelNodes--) {
                TreeNode* node = q.front(); 
                q.pop();
                levelSum += node->val;     
                if(node->left) 
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
            }                
        }
        
        return levelSum;
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        return bfs(root);
    }
};