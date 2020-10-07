/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head) return head;

        int size = 0;
        ListNode* node = head;
        ListNode *lastNode = nullptr;
        while(node){
            size++;
            lastNode = node;
            node = node->next;
        }
        k %= size;
        if(k==0) return head;
        
        ListNode *prevNode = nullptr;
        node = head;
        for(int i=0; i<(size-k); i++) {
            prevNode = node;
            node = node->next;
        }
        prevNode->next = nullptr;
        lastNode->next = head;
        
        return node;
    }
};