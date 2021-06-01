/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
// O(log N * log N) Solution
class Solution {
private:
    int findH(TreeNode* root) {
        return (!root->left) ? 0 : 1 + findH(root->left); 
    } 
    
    // O(h)
    bool isComplete(TreeNode* root, int h) {
        return (!root) ? (h == -1) : isComplete(root->right, h-1);
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = findH(root);

        int maxNodes = 1, maxBottomNodes = 1;
        for(int i=1; i<=h; i++) {
            maxBottomNodes *= 2;
            maxNodes += maxBottomNodes;
        }

        int halfOfMaxBottomNodes = maxBottomNodes/2;
        
		// O(h) * O(h)
        TreeNode* current = root;
        while (h-->0) {
            if (isComplete(current->left, h)) 
                current = current->right;
            else {
                maxNodes -= halfOfMaxBottomNodes;
                current = current->left;
            }
            halfOfMaxBottomNodes /= 2;
        }
        
        return (!current) ? --maxNodes : maxNodes;
    }
};