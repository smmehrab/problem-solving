/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    Node* flatten(Node* head) {
        Node* headOrigin = head;

        while(head){
            if(head->child){
                Node* child = head->child;
                while(child->next){
                    child = child->next;
                }

                if(head->next){
                    child->next = head->next;
                    child->next->prev = child;
                }

                head->next = head->child;
                head->next-> prev = head;
                head->child = NULL;
            }

            head = head->next;
        }

        return headOrigin;
    }
};