/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* cloneNode(Node* node, vector<Node*>& clone) {
        if(!node || clone[node->val]) return clone[node->val];
        clone[node->val] = new Node(node->val);
        for(Node* neighbor : node->neighbors) clone[node->val]->neighbors.push_back(cloneNode(neighbor, clone));
        return clone[node->val];
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        vector<Node*> clone(110, nullptr);
        return cloneNode(node, clone);
    }
};