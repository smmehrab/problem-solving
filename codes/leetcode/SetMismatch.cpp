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
    vector<int> findErrorNums(vector<int>& nums) {
        int index, duplicate, missing;
        for(int num : nums) {
            index = abs(num)-1;
            if(nums[index]<0) duplicate = index+1;
            else nums[index] *= (-1);
        }
        
        index = 0;
        for(int num : nums) {
            if(num>0) {
                missing = index+1;
                break;
            }
            else index++;
        }

        vector<int> errorNums { duplicate, missing };
        return errorNums;
    }
};