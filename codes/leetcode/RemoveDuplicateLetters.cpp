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
    string removeDuplicateLetters(string word) {
        stack<int> letters;
        set<int> added;
        map<char, int> frequency;
        for(char letter : word) frequency[letter]++;

        for(char letter : word) {
            if(added.find(letter)==added.end()) {
                while(!letters.empty() && letter<letters.top() && frequency[letters.top()]>0) {
                    added.erase(added.find(letters.top()));
                    letters.pop();                    
                }
                letters.push(letter);
                added.insert(letter);
            }
            frequency[letter]--;
        }
        
        string result="";
        while(!letters.empty()) {
            result.push_back(letters.top());
            letters.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};