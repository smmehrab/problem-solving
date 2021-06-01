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
    vector<string> summaryRanges(vector<int>& numbers) {
        if(numbers.size()==0) return {};

        vector<string> ranges;
        string range;
        int first=numbers[0], last=numbers[0];
        for(int number : numbers) {
            if(number>last+1) {
                range = (first!=last) ? to_string(first)+"->"+to_string(last) : to_string(first);
                ranges.push_back(range);
                first = number;
            }
            last = number;
        }
        range = (first!=last) ? to_string(first)+"->"+to_string(last) : to_string(first);
        ranges.push_back(range);
        return ranges;
    }
};