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
    int smallestRepunitDivByK(int k) {
        int n = 0;
        for (int len=1; len<=k+1; len++) {
            n = ((n*10)+1)%k;
            if (n==0) return len;  
        }
        return -1;
    }
};