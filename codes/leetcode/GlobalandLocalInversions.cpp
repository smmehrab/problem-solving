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
    bool isIdealPermutation(vector<int>& nums) {
        int index=0;
        for (int num : nums) {
            if(abs(num-index)>1)
                return false;
            index++;
        }
        return true;
    }
};