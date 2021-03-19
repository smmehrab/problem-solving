#include<bits/stdc++.h> 
using namespace std; 

class Node { 
public:
	int value;
	int hDistance; 
	Node *left, *right;

	Node(int value) { 
		this->value = value; 
		this->hDistance = INT_MAX; 
		this->left = this->right = nullptr; 
	} 
}; 

void bottomView(Node *root) { 
	if (!root) 
		return; 

	int hDistance = 0; 
	root->hDistance = hDistance; 

	map<int, int> nodeWith; 

	queue<Node*> q; 
	q.push(root);
	while (!q.empty()) { 
		Node *node = q.front(); 
		q.pop(); 

		hDistance = node->hDistance; 
		nodeWith[hDistance] = node->value; 

		if (node->left) { 
			node->left->hDistance = hDistance-1; 
			q.push(node->left); 
		} 

		if (node->right) { 
			node->right->hDistance = hDistance+1; 
			q.push(node->right); 
		} 
	} 

    cout << "Bottom View:" << endl;
	for (auto entry = nodeWith.begin(); entry != nodeWith.end(); entry++) 
		cout << entry->second << " ";
    cout << endl;
} 

int main() { 
	Node *root = new Node(5); 
	root->left = new Node(3); 
	root->right = new Node(7); 
	root->left->left = new Node(1); 
	root->left->right = new Node(4); 
	root->right->left = new Node(6); 
	root->right->right = new Node(9); 
	root->left->left->left = new Node(0); 
	root->right->right->left = new Node(8); 

	bottomView(root); 
	return 0; 
} 