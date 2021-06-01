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
private:
    vector<ListNode*> nodes;
    int numberOfNodes;
public:
    Solution(ListNode* head) {
        ListNode *node = head;
        while(node) {
            nodes.push_back(node);
            node = node->next;
        }
        numberOfNodes = nodes.size();
    }
    
    int getRandom() {
        int randomIndex = rand()%numberOfNodes;
        return nodes[randomIndex]->val;
    }
};