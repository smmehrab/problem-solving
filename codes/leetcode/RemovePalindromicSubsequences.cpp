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
    int removePalindromeSub(string s) {
        if (s == "") 
            return 0;
        for (int i=0, j=s.size()-1; i<j; i++, j--)
            if (s[i] != s[j]) 
                return 2;
        return 1;
    }
};