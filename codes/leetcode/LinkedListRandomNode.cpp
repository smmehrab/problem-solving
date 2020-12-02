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