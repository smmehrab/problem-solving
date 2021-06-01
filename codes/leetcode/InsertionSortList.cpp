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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sortedHead = new ListNode();
        ListNode *previousNode, *currentNode = head, *nextNode, *nextCurrent;

        while (currentNode) {
            previousNode = sortedHead;
            nextNode = sortedHead->next;
            
            while (nextNode && currentNode->val>=nextNode->val) {
                previousNode = nextNode;
                nextNode = nextNode->next;
            }

            nextCurrent = currentNode->next;
            currentNode->next = nextNode;
            previousNode->next = currentNode;
            currentNode = nextCurrent;
        }

        sortedHead = sortedHead->next;
        return sortedHead;
    }
};