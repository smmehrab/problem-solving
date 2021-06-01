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
    int missingNumber(vector<int>& nums) {
        int x = 0, i = 1;
        for(int num : nums) x ^= num ^ i++;
        return x;
    }
};