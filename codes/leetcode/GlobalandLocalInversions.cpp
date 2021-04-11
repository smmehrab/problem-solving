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