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
    ListNode* reverse(ListNode* head) {
        ListNode* prevNode = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prevNode;
            prevNode = head;    
            head = nextNode;
        }
        return prevNode;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        slow = reverse(slow);
        while (slow) {
            if (slow->val!=fast->val) 
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};