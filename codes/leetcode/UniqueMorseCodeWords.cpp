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
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> uniqueEncodings;
        string encoding;
        
        for (string word : words){
            encoding = "";
            for (char letter : word) encoding += encode[letter-97];
            uniqueEncodings.insert(encoding);
        }

        return uniqueEncodings.size();
    }
};