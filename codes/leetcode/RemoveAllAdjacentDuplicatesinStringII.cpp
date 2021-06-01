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
    string removeDuplicates(string s, int k) {
        stack<int> st;
        
        int index = 0;
        st.push(index++);
        for (int i=1; i<s.size(); i++, index++) {
            s[index] = s[i];
            if (index == 0 || s[index] != s[index-1]) 
                st.push(index);
            else if (index-st.top()+1 == k) {
                index = st.top()-1;
                st.pop();
            }
        }
        return s.substr(0, index);
    }
};