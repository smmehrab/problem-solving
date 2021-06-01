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
    int addDigits(int num) {
        if(num>=0 && num<=9) 
            return num; 
        else if(num%9==0) 
            return 9; 
        else 
            return (num%9); 
	}
};