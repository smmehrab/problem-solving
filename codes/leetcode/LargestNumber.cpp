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
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for(int num : nums)
            numStrings.push_back(to_string(num));
        
        sort(numStrings.begin(), numStrings.end(), [] (string s1, string s2) {
            return (s1+s2) > (s2+s1);
        });
        
        string number;
        for(string numString : numStrings)
            number += numString;

        return (number[0]=='0') ? "0" : number;
    }
};