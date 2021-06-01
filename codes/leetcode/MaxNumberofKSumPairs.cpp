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
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1, operations=0;
        while(low<high) {
            if(nums[low]+nums[high]==k) operations++, low++, high--;
            else if(nums[low]+nums[high]<k) low++;
            else if(nums[low]+nums[high]>k) high--;
        }
        return operations;
    }
};