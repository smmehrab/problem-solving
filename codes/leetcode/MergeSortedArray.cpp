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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, index=m+n-1;
        while(i>=0 || j>=0) {
            if(i<0) nums1[index--] = nums2[j--];
            else if(j<0) nums1[index--] = nums1[i--];
            else if(nums1[i]>nums2[j]) nums1[index--] = nums1[i--];
            else nums1[index--] = nums2[j--];
        }
    }
};