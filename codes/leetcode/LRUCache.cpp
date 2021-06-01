/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Node {
public:
    int key;
    int value;
    Node* next;
    Node* previous;

    Node (int key, int value) {
        this->key = key;
        this->value = value;
    }

    Node (int key, int value, Node* next, Node* previous) {
        this->key = key;
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
};

class LRUCache {
private:
    int capacity;
    
    map<int, Node*> pageTable;
    int entryCount;
    
    Node* head;
    Node* tail;

    // Promote the most recently used key to the front
    void promote(Node* node) {
        if (node == head)
            return;
        
        if(node->previous) node->previous->next = node->next;
        if (node->next) node->next->previous = node->previous;
        
        node->next = head;
        head->previous = node;
        head = node;

        if(node == tail) 
            tail = node->previous;
    }

public:
    LRUCache(int capacity) {
       this->capacity = capacity;
       this->entryCount = 0;
       this->head = nullptr;
       this->tail = nullptr; 
    }
    
    int get(int key) {
        if (pageTable.find(key) != pageTable.end()) {
            promote(pageTable[key]);
            return pageTable[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // Already Exists
        if (pageTable.find(key) != pageTable.end()) {
            Node* node = pageTable[key];
            node->value = value;
            promote(node);
        }
        // Capacity Full
        else if (entryCount == capacity) {
            pageTable.erase(tail->key);
            tail->key = key;
            tail->value = value;
            pageTable.insert({key, tail});
            promote(tail);
        }
        // New Valid Insertion
        else {
            entryCount++;
            Node* node = new Node(key, value);
            node->next = head;
            if (head) 
                head->previous = node;
            else
                tail = node;
            head = node;
            pageTable.insert({key, node});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */