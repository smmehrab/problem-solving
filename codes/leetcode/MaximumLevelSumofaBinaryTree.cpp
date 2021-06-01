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
    map<int, int> sums;
    void traverse(TreeNode* root, int level) {
        if(!root) return;
        if(sums.find(level)!=sums.end()) sums[level] += root->val;
        else sums.insert({level, root->val});
        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        traverse(root, 1);
        int maxSum, level;
        for (map<int, int>::iterator sum = sums.begin(); sum != sums.end(); ++sum) {
            if(sum == sums.begin() || sum->second>maxSum) {
                maxSum = sum->second;
                level = sum->first;
            }
        } 
        
        return level;
    }
};