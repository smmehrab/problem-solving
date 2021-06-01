/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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
    map<int, int> sumCount;
    int findSubtreeSum(TreeNode* root) {
        if(!root) return 0;
        
        int sum;
        if(!root->left && !root->right) sum = root->val;
        else sum = findSubtreeSum(root->left) + (root->val) + findSubtreeSum(root->right);
        
        sumCount[sum]++;
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int totalSum = findSubtreeSum(root);
        
        int maxFrequency = INT_MIN;
        for(auto entry=sumCount.begin(); entry!=sumCount.end(); entry++) 
            maxFrequency = max(maxFrequency, entry->second);
        
        vector<int> sumWithMaxFrequency;
        for(auto entry=sumCount.begin(); entry!=sumCount.end(); entry++) 
            if(entry->second==maxFrequency) 
                sumWithMaxFrequency.push_back(entry->first);
        
        return sumWithMaxFrequency;
    }
};