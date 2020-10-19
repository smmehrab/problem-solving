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
private:
    ListNode* partition(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1 && !head2) return head1;

        ListNode *head = nullptr, *current = nullptr;
        if (head1->val <= head2->val) {
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }
        current = head;

        while (head1 && head2) {
            if (head1->val <= head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        current->next = (head1) ? head1 : head2;
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* secondHead = partition(head);
        head = sortList(head); 
        secondHead = sortList(secondHead);
        head = merge(head, secondHead);
        return head;
    }
};