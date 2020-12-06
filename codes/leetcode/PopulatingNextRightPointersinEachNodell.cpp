class Solution {
public:
    Node* connect(Node* root) {        
        Node* current = root;
        Node* nextLeftMost = nullptr;
        Node* adjacent = nullptr;

        while(current) {
            if(current->left) {
                if(!nextLeftMost) nextLeftMost = current->left;
                if(current->right) current->left->next = current->right;
                else {
                    adjacent = current->next;
                    while(adjacent && !adjacent->left && !adjacent->right) adjacent = adjacent->next;
                    if(adjacent) current->left->next = (adjacent->left) ? adjacent->left : adjacent->right;
                }
            }

            if(current->right) {
                if(!nextLeftMost) nextLeftMost = current->right;
                adjacent = current->next;
                while(adjacent && !adjacent->left && !adjacent->right) adjacent = adjacent->next;
                if(adjacent) current->right->next = (adjacent->left) ? adjacent->left : adjacent->right;
            }
            
            current = (current->next) ? current->next : nextLeftMost;
            nextLeftMost = (current==nextLeftMost) ? nullptr : nextLeftMost;
        }
        
        return root;
    }
};