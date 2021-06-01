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
    string minRemoveToMakeValid(string s) {
        string validS = "";
        int n = s.size(), open = 0, close = 0;
        
        // Normal Pass
        for(int i=0;i<n;++i){
            if(s[i]=='(') open++;
            else if(s[i]==')') { 
                if(open==0) s[i]='#';
                else open--;
            }
        }
        
        // Reverse Pass
        for(int i=n-1;i>=0;--i){
            if(s[i]==')') close++;
            else if(s[i]=='('){ 
                if(close==0) s[i]='#';
                else close--;
            }
        }
        
        for(char c : s) {
            if(c!='#') validS += c;
        }
        return validS;
    }
};