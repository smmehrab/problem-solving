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
    int longestConsecutive(vector<int>& numbers) {
        int consecutive=0, current;
        unordered_set<int> set;
        
        for(int number : numbers) set.insert(number);
        for(int number : set) {
            if(set.find(number-1)==set.end()) {
                current = 1;
                while(set.find(number+current)!=set.end()) current++;
                consecutive = max(consecutive, current);
            }
        }
        
        return consecutive;
    }
};