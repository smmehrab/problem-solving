class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue <int, vector<int>, greater<int> > minHeap;
        for(int i=0; i<k; i++) {
            ListNode *node = lists[i];
            while(node) {
                minHeap.push(node->val);
                node = node->next;
            }
        }
        
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        while(!minHeap.empty()) {
            ListNode *minNode = new ListNode(minHeap.top());
            current->next = minNode;
            current = current->next;
            minHeap.pop();
        }
        
        head = head->next;
        return head;
    }
};