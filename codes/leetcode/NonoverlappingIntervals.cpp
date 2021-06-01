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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int numberOfIntervals = intervals.size();
        
        if(numberOfIntervals == 0) return 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        
        int maximumEndTime = INT_MIN;
        int minOverlapped = numberOfIntervals;
        for(vector<int> interval : intervals){  
            if(interval[0] >= maximumEndTime){
                minOverlapped--;
                maximumEndTime = interval[1];
            }
        }
        
        return minOverlapped;
    }
};