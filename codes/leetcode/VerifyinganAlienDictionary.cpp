class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int numberOfLetters = order.size();
        unordered_map<char, int> orderOf;
        for (int i=0; i<numberOfLetters; i++) {
            orderOf[order[i]] = i;
        }

        int numberOfWords = words.size();
        for (int i=0; i<numberOfWords-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            int limit = min(word1.size(), word2.size());
            bool rightOrder = false;
            
            for (int j=0; j<limit; j++) {
                if(word1[j]!=word2[j]) {
                    if (orderOf[word1[j]] > orderOf[word2[j]])
                        return false;
                    else {
                        rightOrder = true;
                        break;
                    }
                }
            }
            
            if(!rightOrder && word1.size()>word2.size()) 
                return false;
        }
        
        return true;
    }
};