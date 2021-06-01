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
    bool halvesAreAlike(string s) {
        string vowels = "aeiou";
        int half = s.size()/2, vowelCountDiff = 0;
        for (int i=0, j=half; i<half; i++, j++) {
            if (vowels.find(tolower(s[i])) != string::npos) 
                vowelCountDiff++;
            if (vowels.find(tolower(s[j]))!= string::npos) 
                vowelCountDiff--;
        }
        return (vowelCountDiff == 0);
    }
};