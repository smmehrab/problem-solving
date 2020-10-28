/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next) return nullptr;

        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        
        if(fast!=slow) return nullptr;
        
        ListNode* cycleHead = slow;
        slow = head;
        while(cycleHead != slow){
            slow = slow->next;
            cycleHead = cycleHead->next;
        }
        return cycleHead;        
    }
};