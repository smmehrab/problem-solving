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
    bool buddyStrings(string s1, string s2) {
        if (s1.empty() || s1.size()!=s2.size()) return false;
        int len = s1.size();
        
        if (s1==s2) {
            if(len > 26) return true;
            map<char, int> frequency;
            for (char letter : s1) {
                if (frequency.find(letter-'a')!=frequency.end()) return true;
                frequency[letter-'a'] = 1;
            }
            return false;
        }

        int difCount = 0;
        char swapableS1, swapableS2;
        for(int i=0; i<len; i++) {
            if (s1[i] != s2[i]) {
                if (difCount == 0) swapableS1 = s1[i], swapableS2 = s2[i], difCount++;
                else if (difCount >= 2) return false;
                else if (difCount==1 && (s1[i] != swapableS2 || s2[i] != swapableS1)) return false;
                else difCount++;
            }
        }
        return (difCount == 2);
    }
};  