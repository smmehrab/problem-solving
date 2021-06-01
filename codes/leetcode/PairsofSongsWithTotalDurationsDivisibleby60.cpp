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
    int numPairsDivisibleBy60(vector<int>& durations) {
        vector<int> songs(60, 0);
        int numberOfPairs = 0, remainder;
        for(int duration : durations) {
            remainder = duration % 60;
            numberOfPairs += songs[(60-remainder)%60];
            songs[remainder]++;
        }
        return numberOfPairs;
    }
};