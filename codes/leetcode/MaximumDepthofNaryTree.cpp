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
    int dfs(Node* root){
        if(!root) return 0;
        int depth = 0;
        for(Node* child : root->children) depth = max(depth, dfs(child));
        return 1+depth;
    }
public:
    int maxDepth(Node* root) {
        return dfs(root);
    }
};