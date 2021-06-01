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
    int singleNumber(vector<int>& numbers) {
        int appearedOnce = 0, appearedTwice = 0, commonBitsMask = 0;
        for(int number : numbers) {
            appearedTwice |= (appearedOnce & number);
            appearedOnce ^= number;
            commonBitsMask = ~(appearedOnce & appearedTwice);
            appearedOnce &= commonBitsMask;
            appearedTwice &= commonBitsMask;
        }
        
        return appearedOnce;
    }
};