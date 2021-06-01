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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* first;
        ListNode* second = head;
        
        for (int i=0; i<k-1; i++) 
            current = current->next; 
        first = current; 
        
        current = current->next;        
        while (current) { 
            current = current->next;
            second = second->next;
        }
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};