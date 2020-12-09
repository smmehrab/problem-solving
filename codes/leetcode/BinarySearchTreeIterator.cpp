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