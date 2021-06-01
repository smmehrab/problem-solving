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
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> smt, tms;
        for(int i=0; i<n; i++) {
            if(smt.find(s[i])==smt.end() && tms.find(t[i])==tms.end()) {
                smt.insert({s[i], t[i]});
                tms.insert({t[i], s[i]});
                continue;
            }
            if(tms.find(t[i])!=tms.end() && tms[t[i]] != s[i]) 
                return false;
            if(smt.find(s[i])!=smt.end() && smt[s[i]] != t[i]) 
                return false;
        }
        return true;
    }
};