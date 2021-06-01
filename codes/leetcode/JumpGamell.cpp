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
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n<=1) return 0;
        
        int minimumNumberOfJumps = 0;
        for(int i=0, maximumReach=0, currentReach=0; i<n-1; i++) {
            maximumReach = max(maximumReach, i+nums[i]);
            if(i==currentReach) {
                minimumNumberOfJumps++;
                currentReach = maximumReach;
            }
            if(currentReach>=n-1) break;
        }
        return minimumNumberOfJumps;
    }
};