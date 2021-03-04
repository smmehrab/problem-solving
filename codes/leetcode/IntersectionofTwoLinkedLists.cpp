/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int findLen(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* fastForward(ListNode* current, int lenDifference) {
        while(lenDifference--) current = current->next;
        return current;
    }
    
public:    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        
        int lenA = findLen(headA);
        int lenB = findLen(headB);
        ListNode* currentA = headA;
        ListNode* currentB = headB;
    
        if(lenA>lenB) currentA = fastForward(currentA, lenA-lenB);
        else currentB = fastForward(currentB, lenB-lenA);
        while(currentA!=currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }
        
        return currentA;
    }
};