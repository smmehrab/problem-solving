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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int mountainLength = 0, start = 0, end;
        
        while (start<n) {
            end = start;
            if (end+1<n && arr[end]<arr[end+1]) {
                while (end+1<n && arr[end]<arr[end+1]) end++;
                if (end+1<n && arr[end]>arr[end+1]) {
                    while (end+1<n && arr[end]>arr[end+1]) end++;
                    mountainLength = max(mountainLength, end-start+1);
                }
            }
            start = max(start+1, end);
        }

        return mountainLength;
    }
};