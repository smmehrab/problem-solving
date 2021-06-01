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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1Head = new ListNode(0);
        ListNode* p1Current = p1Head;
        ListNode* p2Head = new ListNode(0);
        ListNode* p2Current = p2Head;
        
        while (head) {
            if (head->val < x) {
                p1Current->next = head;
                p1Current = p1Current->next;
            } 
            else {
                p2Current->next = head;
                p2Current = p2Current->next;
            }

            head = head->next;
        }

        p2Current->next = nullptr;
        p1Current->next = p2Head->next;
        p1Head = p1Head->next;
        return p1Head;
    }
};