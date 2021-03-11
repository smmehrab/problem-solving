class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            if (nums[l]==nums[r]) {
                while(l<=r) {
                    if (nums[l++]==target) return true;
                }
                return false;
            }
            int mid=(l+r)/2;
            if (nums[mid]==target) return true;
            if (nums[l]<nums[r]) {
                if (nums[mid]>target) r=mid-1;
                else l=mid+1;
            }
            else {
                if (nums[mid]>=nums[l]) {
                    if (target<nums[mid]&&target>=nums[l]) r=mid-1;
                    else l=mid+1;
                }
                else {
                    if (target>nums[mid]&&target<=nums[r]) l=mid+1;
                    else r=mid-1;
                }
            }
        }
        return false;
    }
};