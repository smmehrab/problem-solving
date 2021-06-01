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
    vector<int> runningSum(vector<int>& nums) {
        int previous;
        bool isFirst = true;
        for(int &num : nums) {
            if(isFirst) 
                isFirst = false;
            else {
                num += previous;   
            }
            previous = num;
        }
        return nums;
    }
};