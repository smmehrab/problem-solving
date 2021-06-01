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
	void inorderTraversal(TreeNode* node, vector<int>& elements) {
		if (!node) return;
		inorderTraversal(node->left, elements);
		elements.push_back(node->val);
		inorderTraversal(node->right, elements);
	}

public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements1;
		vector<int> elements2;
        int numberOfElements1, numberOfElements2;

		inorderTraversal(root1, elements1);
		inorderTraversal(root2, elements2);

		numberOfElements1 = elements1.size();
        numberOfElements2 = elements2.size();

        if (numberOfElements1 == 0) return elements2;
        if (numberOfElements2 == 0) return elements1;
        
		vector<int> allElements(numberOfElements1+numberOfElements2);
        merge(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), allElements.begin()); 
		
		return allElements;
	}
};