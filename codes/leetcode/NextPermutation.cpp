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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2, j = n-1;
        
        while (i>=0 && nums[i] >= nums[i+1]) i--;
        if(i>=0) {
            while (j>=0 && nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);            
        }

        reverse(nums.begin()+i+1, nums.end());
    }
};