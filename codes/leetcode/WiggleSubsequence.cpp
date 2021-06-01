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
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        
        int diff;
        int previousDiff = nums[1]-nums[0];
        int len = (previousDiff==0) ? 1 : 2;
        
        for(int i=2; i<n; i++) {
            diff = nums[i]-nums[i-1];
            if (diff!=0 && (diff*previousDiff)<=0) {
                len++;
                previousDiff = diff;
            }
        }
        
        return len;
    }
};