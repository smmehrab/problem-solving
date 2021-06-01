/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
    private:
        int depth(TreeNode* node) {
            if(!node) return 0;
            return 1 + max(depth(node->left), depth(node->right));
        }

    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            if(!root) return root;
            int leftDepth = depth(root->left);
            int rightDepth = depth(root->right);
            if(leftDepth == rightDepth) return root;
            else if(leftDepth > rightDepth) return subtreeWithAllDeepest(root->left);			
            else return subtreeWithAllDeepest(root->right);
        }
};