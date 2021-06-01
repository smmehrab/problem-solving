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
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int nonOverlappingIntervals=intervals.size(), covered=INT_MIN;
        
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) { 
                 return (a[0]!=b[0]) ? a[0]<b[0] : a[1]>b[1];
        });
        
        for(vector<int> interval : intervals) {
            if(interval[1]<=covered) nonOverlappingIntervals--;
            else covered = interval[1];
        }

        return nonOverlappingIntervals;
    }
};