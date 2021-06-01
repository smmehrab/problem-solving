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
    int minMoves2(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        
        int n = numbers.size();
        int median = numbers[(n/2)];
        int numberOfMoves = 0;
        
        for(int number : numbers) 
            numberOfMoves += abs(median-number);
        
        return numberOfMoves;
    }
};