class WordDictionary {
private:
    struct Node {
        bool isLeaf; 
        vector<Node*> letters; 

        Node() { 
            isLeaf = false;
            letters = vector<Node*>(26, nullptr);
        }
    };

    Node *root;
        
    bool find(int position, Node *current, string word) {
        if (current == nullptr || position>word.size()) return false; 
        
        while (position < word.size()) {
            int index = word[position] - 'a';

            if (word[position] == '.') { 
                bool found = false;
                for (int j=0; j<26; j++) { 
                    if (current->letters[j] == nullptr) continue;
                    found = find(position+1, current->letters[j], word);
                    if (found == true) break;
                }
                return found;
            }
            
            if (current->letters[index] == nullptr) return false;
            current = current->letters[index];
            position++;
        }
        
        if (position == word.size()) return current->isLeaf;
        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *current = root;
        for (char letter: word) {
            int index = letter - 'a';

            if (current->letters[index] == nullptr) { 
                current->letters[index] = new Node(); 
            }
            
            current = current->letters[index];
        }
        
        current->isLeaf = true;
    }
    
    bool search(string word) {
        return find(0, root, word);
    }
};
