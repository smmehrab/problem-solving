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
    bool arrayStringsAreEqual(vector<string>& a1, vector<string>& a2) {
        string s1="", s2="";
        for(string a : a1) s1 += a; 
        for(string a : a2) s2 += a; 
        return s1==s2;
    }
};