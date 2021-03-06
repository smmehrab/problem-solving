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
private:
    string encode(string word) {
        unordered_map<char,string> mp;
        string encoded = "";
        char code = 'a';
        for(char letter : word) {
            if(mp.find(letter)==mp.end()) {
                encoded += code;
                mp[letter] = code;
                code++;
            }
            else
                encoded += mp[letter];
        }
        return encoded;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        pattern = encode(pattern);
        vector<string> validWords;
        for(string word : words) {
            if(encode(word)==pattern)
                validWords.push_back(word);
        }
        return validWords;
    }
};