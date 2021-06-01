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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1010] = {};
        for(vector<int> trip : trips) stops[trip[1]] += trip[0], stops[trip[2]] -= trip[0];
        for(int i=0; i<1010 && capacity>=0; i++) capacity -= stops[i];
        return capacity>=0;
    }
};