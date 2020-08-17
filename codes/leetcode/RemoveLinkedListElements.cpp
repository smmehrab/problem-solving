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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        struct ListNode *node = (struct ListNode *) calloc(1, sizeof(struct ListNode));
        node->next = head;
        head = node;

        while (node->next)
        {
            if (node->next->val == val)
                node->next = node->next->next;
            else
                node = node->next;
        }

        return head->next;
    }
};
