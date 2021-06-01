/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class BSTIterator {
private:
    vector<int> nodes;
    int index = 0;

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        nodes.push_back(root->val);
        traverse(root->right);  
    }
    
public:
    BSTIterator(TreeNode* root) {
        traverse(root);  
    }
    
    int next() {
        return nodes[index++];
    }
    
    bool hasNext() {
        return (index<nodes.size());
    }
};