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
    string intToRoman(int number) {
        string key[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string roman = "";
        for (int i=0; i<13; i++) {
            while (number >= value[i]) {
                roman += key[i]; 
                number -= value[i];
            }
            if(number==0) break;
        }
        return roman;
    }
};