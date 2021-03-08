class Node {
public:
    int key;
    int value;
    Node* next;
    
    Node(int key, int value, Node* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class MyHashMap {
private:
    int numberOfSlots = 997;
    vector<Node*> hashTable;
    
    int hash(int key) {
        return key%numberOfSlots;
    }
    
    Node* search(int key) {
        int index = hash(key);
        Node* node = hashTable[index];
        while (node && node->key != key) 
            node = node->next;
        return node;
    }
    
public:
    MyHashMap() {
        numberOfSlots = 997;
        hashTable = vector<Node*>(numberOfSlots, nullptr);
    }

    void put(int key, int value) {
        Node* node = search(key);
        if(node)
            node->value = value;
        else{
            int index = hash(key);
            Node* node = new Node(key, value, hashTable[index]);
            hashTable[index] = node;
        }
    }    
    
    int get(int key) {
        Node* node = search(key);
        return node ? node->value : -1;
    }    
    
    void remove(int key) {
        int index = hash(key);
        Node* node = hashTable[index];
        if(node) {
            if (node->key == key) 
                hashTable[index] = node->next;
            else {
                while(node->next && node->next->key != key) 
                    node = node->next;
                if (node->next && node->next->key == key) 
                    node->next = node->next->next;
            } 
        }
    }
};