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
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c=='(' || c=='[' || c=='{') st.push(c);
            else if (st.empty()) return false;
            else if(c==')') {
                if (st.top()=='(') st.pop();
                else return false;   
            }
            else if(c=='}') {
                if (st.top()=='{') st.pop();
                else return false;   
            }
            else if(c==']') {
                if (st.top()=='[') st.pop();
                else return false;   
            }
        }
        
        return st.empty();
    }
};