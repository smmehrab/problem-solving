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
    int low, high, sum;
    void solve(TreeNode* node) {
        if(!node) 
            return;
        if (node->val>=low && node->val<=high)
            sum += node->val;
        if (node->val>low)
            solve(node->left);
        if (node->val<high)
            solve(node->right);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        sum = 0;
        solve(root);
        return sum;
    }
};