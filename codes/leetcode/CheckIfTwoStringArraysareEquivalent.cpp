class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a1, vector<string>& a2) {
        string s1="", s2="";
        for(string a : a1) s1 += a; 
        for(string a : a2) s2 += a; 
        return s1==s2;
    }
};