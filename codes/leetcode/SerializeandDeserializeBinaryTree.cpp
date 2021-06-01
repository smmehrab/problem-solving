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
    string data;
    TreeNode* head;
    
    void traverseTree(TreeNode* root) {
        if(!root) {
            data += "n ";
            return;
        }
        data += to_string(root->val) + " ";
        traverseTree(root->left);
        traverseTree(root->right);
    }
    
    TreeNode *buildTree(string &data, int &index) {
        if(data[index]=='n') {
            index++;
            return NULL;
        }

        string value = "";
        while(data[index]!=' ') value += data[index++];
        
        TreeNode *root = new TreeNode(stoi(value));
        root->left = buildTree(data, ++index);
        root->right = buildTree(data, ++index);
        return root;
    }
    
public:
    string serialize(TreeNode* root) {
        this->data = "";
        traverseTree(root);
        return data;
    }

    TreeNode* deserialize(string data) {
        int index = 0;
        return buildTree(data, index);
    }
};