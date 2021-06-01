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
    int minOperations(int n) {
        if(n&1){ 
            n = ((n-1)/2);
            return n*(n+1);
        }
        n /= 2;
        return (n*n); 
    }
};