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
    vector<int> sortedSquares(vector<int>& numbers) {
        for(int &number : numbers) number *= number;
        sort(numbers.begin(), numbers.end());
        return numbers;
    }
};