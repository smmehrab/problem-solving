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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tail, *current, *head=nullptr;
        int  d1, d2, s, c=0;
              
        while(l1 || l2) {
            d1=0, d2=0;
            if(l1) d1 = l1->val;
            if(l2) d2 = l2->val;
            s = d1+d2+c;          
            c = (s>=10) ? 1 : 0; 
            
            current = new ListNode(s%10);
            if(!head) head = current;
            else tail->next = current;
            tail = current;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
            
        if(c>0) tail->next = new ListNode(c);
        return head;
    }
};