
class Solution {
private:
    int n;
    vector<int> numbers;

    class Node{
    public:
        Node*left;
        Node*right;   
    };

    void insert(int number, Node*root){
        Node* current = root;
        for(int i=31; i>=0; i--){
            int bit = (number>>i) & 1;
            if(bit==0) {
                if(!current->left) current->left = new Node(); 
                current = current->left;
            }
            else {
                if(!current->right) current->right = new Node();
                current = current->right;
            }
        }
    }

    int findXorIncluding(int number, Node* root){
        Node* current = root;
        int maximumXorIncludingNumber =0;
        for(int i=31; i>=0; i--){
            int bit = (number>>i) & 1;
            if(bit==0){
                if(current->right){
                    current = current->right;
                    maximumXorIncludingNumber += (int) pow(2, i);
                }
                else current = current->left;
            }
            
            else{
                if(current->left){
                    current = current->left;
                    maximumXorIncludingNumber += (int) pow(2, i);
                }
                else current = current->right;
            }
        }

        return maximumXorIncludingNumber; 
    }

public:    
    int findMaximumXOR(vector<int>& numbers) {
        this->numbers = numbers;
        this->n = numbers.size();
        if(n==0) return 0;

        Node* root = new Node();
        int maximumXor = INT_MIN;

        for(int number : numbers){
            insert(number, root);
            maximumXor = max(maximumXor, findXorIncluding(number, root)); 
        }

        return maximumXor;
    }
};