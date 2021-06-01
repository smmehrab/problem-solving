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
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        int maxx=1;
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(1);

        for(int i=2; i<n+1; i++){
            nums.push_back(nums[(i-(i%2))/2]);
            if(i%2 != 0) nums[i] += nums[(i-(i%2))/2 + 1];
            maxx = max(maxx, nums[i]);
        }
                
        return maxx;
    }
};