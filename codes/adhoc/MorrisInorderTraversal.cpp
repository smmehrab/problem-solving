// Constant Space Inorder Traversal
class Node{
public:
    int val;
    Node* left;
    Node* right;
};

void morrisTraversal(Node *root, vector<int> &traversal) {
    TreeNode *current, *predecessor;

    if (!root)
        return;

    current = root;
    while (current) {
        if (!current->left) {
            traversal.push_back(current->val);
            current = current->right;
        }
        else {
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (!predecessor->right) {
                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = nullptr;
                traversal.push_back(current->val);
                current = current->right;
            }
        }
    }
}