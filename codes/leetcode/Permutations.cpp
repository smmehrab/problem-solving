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
private:
    vector<int> nums;
    vector<vector<int>> results;
    
    void heapPermutation(int end) {
        if (end == 0) {
            results.push_back(nums);
            return;
        }

        for (int i=0; i<=end; i++) {
            heapPermutation(end-1);
            if (end%2) swap(nums[0], nums[end]);
            else swap(nums[i], nums[end]);
        }
    }

    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        heapPermutation(nums.size()-1);
        return results;
    }
};