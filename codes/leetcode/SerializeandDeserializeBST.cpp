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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* helper(stringstream& dataStream) {
        string val;
        getline(dataStream, val, '-');
        if(val == "$") return nullptr; 
		
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(dataStream); 
        root->right = helper(dataStream);
        return root;
    }
    
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {	
        return (!root) ? "$" : to_string(root->val) + "-" + serialize(root->left) + "-" + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "$") return nullptr;
        stringstream dataStream(data);
        return helper(dataStream);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;