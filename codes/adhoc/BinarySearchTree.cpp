/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node* left;
    Node* right;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void print(Node* root) {
    if(root) {
        print(root->left);
        cout << root->key << " " << root->value << endl;
        print(root->right);
    }
}

Node* insert(Node* root, int key, int value) {
    if(!root)
        return new Node(key, value);
    else if(key < root->key)
        root->left = insert(root->left, key, value);
    else
        root->right = insert(root->right, key, value);
    return root;
}

Node* leftMost(Node* root) {
    Node* current = root;
    while(current && current->left)
        current = current->left;
    return current;
}

Node* remove(Node* root, int key) {
    if(!root)
        return root;
    else if(key < root->key)
        root->left = remove(root->left, key);
    else if(key > root->key)
        root->right = remove(root->right, key);
    else {
        if(!root->left) 
            return root->right;
        else if(!root->right)
            return root->left;
        Node* rightMinimum = leftMost(root->right);
        root->key = rightMinimum->key;
        root->value = rightMinimum->value;
        root->right = remove(root->right, rightMinimum->key);
    }
    return root;
}

int search(Node* root, int key) {
    if(root) {
        if(key == root->key)
            return root->value;
        else if(key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    return -1;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8, -1);
    root = insert(root, 3, -1);
    root = insert(root, 1, -1);
    root = insert(root, 6, -1);
    root = insert(root, 7, 7);
    root = insert(root, 10, -1);
    root = insert(root, 14, -1);
    root = insert(root, 4, -1);

    cout << "Initial BST: " << endl;
    print(root);

    root = remove(root, 10);

    cout << endl << "After Deleting 10: " << endl;
    print(root);

    cout << "Value with Key 7: " << endl;
    cout << search(root, 7) << endl;

    return 0;
}