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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* result = nullptr;
        int sum=0, carry=0, digit1, digit2;
        while(!s1.empty() || !s2.empty() || carry) {
            
            if(!s1.empty()) {
                digit1 = s1.top();
                s1.pop();
            }
            else digit1 = 0;

            if(!s2.empty()) {
                digit2 = s2.top();
                s2.pop();
            }
            else digit2 = 0;

            sum = (digit1 + digit2 + carry);
            carry = sum/10;

            ListNode* newNode = new ListNode(sum%10, result);
            result = newNode;
        }

        return result;
    }
};