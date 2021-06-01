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
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int num : nums) ans^=num;
        return ans;
    }
};