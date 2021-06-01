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
    bool canJump(vector<int>& nums) {
        int valid = nums.size()-1;
        for (int i=valid; i>=0; i--) valid = (i+nums[i] >= valid) ? i : valid;
        return valid == 0;
    }
};