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
    int titleToNumber(string s) {
        int answer=0;
        for(char letter : s){
            answer *= 26; 
            answer += letter-'A'+1;
        }
        return answer;
    }
};