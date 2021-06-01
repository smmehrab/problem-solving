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
    bool isPalindrome(int x) {
        long long int y=0, digit, tempX=x;
        if(x<0) return false;
        if(x<10) return true;
        
        while(tempX){
            digit = tempX%10;
            y *= 10;
            y += digit;
            tempX /= 10;
        }

        return x == y;
    }
};