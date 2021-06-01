/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int value;
    Node *left, *right;
    Node(int value) { 
		this->value = value; 
		this->left = this->right = NULL;
    }
};
  
Node* insert(Node* root, int value) {
    if (!root) root = new Node(value);
    else if (value < root->value) root->left = insert(root->left, value); 
    else root->right = insert(root->right, value);
    return root;
}
 
bool findPair(Node* root, int k, set<int> &nodes) {
    if (!root) return false;
    
    // Searching Left Subtree
    if (findPair(root->left, k, nodes)) return true;
    
    // Processing Current Node
    if (nodes.find(k-root->value) != nodes.end()) {
        cout << "Pair Found: (" << k - root->value << ", " << root->value << ")" << endl;
        return true;
    }
    else nodes.insert(root->value); 

    // Searching Right Subtree
    return findPair(root->right, k, nodes);
}
 
int main() {
    int numberOfNodes, value, k;
    vector<int> bst;

    cout << "Enter Number of Nodes in BST:" << endl;
    cin >> numberOfNodes;
    cout << "Enter Inorder Traversal of BST:" << endl;
    for(int i=0; i<numberOfNodes; i++) {
        cin >> value;
        bst.push_back(value);
    }
    cout << "Enter k:" << endl;
    cin >> k;

    Node* root = NULL;
    set<int> nodes;
 
    for (int value : bst) root = insert(root, value);
    if (!findPair(root, k, nodes)) cout << "No K Sum Pair Exists" << endl;
 
    return 0;
}