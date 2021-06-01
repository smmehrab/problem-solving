/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* leftmost = root;
        while(leftmost->left) {
            Node* head = leftmost;
            while(head) {
                head->left->next = head->right;
                if(head->next) head->right->next = head->next->left;
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        
        return root;
    }
};