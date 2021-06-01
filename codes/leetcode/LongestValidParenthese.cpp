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
    int longestValidParentheses(string s) {
        int longest = 0;
        
        int left = 0, right = 0;
        for(char c : s) {
            (c=='(') ? left++ : right++;
            if(left == right)
                longest = max(longest, 2*left);
            else if(right>left)
                left=0, right=0;
        }
        
        reverse(s.begin(), s.end());
        
        left=0, right=0;
        for(char c : s) {
            (c=='(') ? left++ : right++;
            if(left == right)
                longest = max(longest, 2*left);
            else if(left>right)
                left=0, right=0;
        }
        
        return longest;
    }
};