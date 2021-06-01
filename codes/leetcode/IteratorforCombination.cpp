/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class CombinationIterator {
private:
    int size, combinationLength;
    bool nextExists;
    string characters;
    vector<int> pointers; 
    unordered_set<string> combinationSet; 

    void setPointers() {
        for (int i = 0; i < combinationLength; i++)
            pointers.push_back(i);
    }

    void incrementPointers() {
        for (int i = combinationLength - 1, j = 0; i >= 0; i--) {
            if (pointers[i] + 1 < size - j++) {
                pointers[i]++;
                for (int n = i + 1; n < combinationLength; n++) 
                    pointers[n] = pointers[n - 1] + 1;
                return;
            }
        }

        nextExists = false;
    }

    string readNextCombination() {
        string nextCombination;
        bool newCombinationFound = false;

        while (!newCombinationFound) {
            nextCombination = "";
            for (int i = 0; i < combinationLength; i++)
                nextCombination += characters[pointers[i]];
            newCombinationFound = combinationSet.find(nextCombination) == combinationSet.end();
            if (!newCombinationFound) { 
                incrementPointers();
                if (!nextExists) return "";
            }
        }

        combinationSet.insert(nextCombination);
        return nextCombination;
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        this->size = characters.length();
        this->combinationLength = combinationLength;
        this->nextExists = true;
        setPointers();
    }

    string next() {
        if (!nextExists) return "";
        string nextCombination = readNextCombination();
        incrementPointers();
        return nextCombination;
    }

    bool hasNext() {
        return nextExists;
    }
};


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class CombinationIterator {
  public:
    int len = 0;
    string chars;
    bool nextState;
    vector<int> state;
    CombinationIterator(string characters, int combinationLength) {
      chars = characters;
      len = combinationLength;
      for(int i = 0; i < len; i++){
        state.push_back(i);
      }
      nextState = true;
    }
    string next() {
      string cur = "";
      for(int i = 0; i < state.size(); i++){
        cur.push_back(chars[state[i]]);
      }
      calculateNext();
      return cur;
    }
    void calculateNext(){
      int i = 0;
      for(i = state.size() - 1; i >= 0; i--){
        if(state[i] + 1 < chars.size() and
        state[i] + (len - i) < chars.size()){
          break;
        }
      }
      if(i < 0){
        setNext(false);
      } else {
        state[i]++;
        for(i = i + 1; i < state.size(); i++){
          state[i] = state[i-1] + 1;
        }
      }
    }
    bool hasNext() {
     return nextState;
    }
    void setNext(bool val){
      nextState = val;
    }
};