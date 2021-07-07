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
	struct Node *left, *right; 
	Node(int value) { 
		this->value = value; 
		this->left = this->right = NULL; 
    }
}; 

Node* buildUtil(vector<int> &postorder, int* index, int min, int max) { 
	if (index < 0) return NULL; 

	int value = postorder[*index];
	Node* root = NULL; 

	if (value > min && value < max) { 
		root = new Node(value); 	 
		if (--*index >= 0) { 
			root->right = buildUtil(postorder, index, value, max); 
			root->left = buildUtil(postorder, index, min, value); 
		} 
	} 
	return root; 
} 

Node *build (vector<int> &postorder, int numberOfNodes) { 
	int index = numberOfNodes-1;
	return buildUtil(postorder, &index, INT_MIN, INT_MAX); 
} 

void printInorder (Node* root) { 
	if (!root) return; 
	printInorder(root->left); 
	cout << root->value << " "; 
	printInorder(root->right);
} 

int main () { 
	int numberOfNodes, value;
	vector<int> postorder;

	cout << "We are going to build a BST from its postorder traversal." << endl; 
	cout << "Enter number of nodes: " << endl;
	cin >> numberOfNodes;
	cout << "Enter space-separated values of the tree's postorder traversal: " << endl;
	for(int i=0; i<numberOfNodes; i++) {
		cin >> value;
		postorder.push_back(value);
	}

	Node *root = build(postorder, numberOfNodes); 
	cout << "BST Inorder: " << endl; 
	printInorder(root); 
	return 0; 
} 