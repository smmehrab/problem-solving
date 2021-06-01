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
    bool checkPossibility(vector<int>& nums) {
        bool possibility = true;
        int n = nums.size(), decreasing=0;        
        for(int i=1; i<n && possibility; i++){
            if(nums[i]<nums[i-1]){
                decreasing++;
                if(decreasing>1 ||(i>1 && i<n-1 && (nums[i+1]<nums[i-1] && nums[i]<nums[i-2]))) 
                    possibility = false;
            }
        }
        return possibility;
    }
};