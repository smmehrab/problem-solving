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
    int search(vector<int>& sorted, int target) {
        return binary_search(sorted.begin(), sorted.end(), target) ? lower_bound(sorted.begin(), sorted.end(), target) - sorted.begin() : -1;
    }
};