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
    int rob(vector<int>& houses) {
        int currentMax = 0, previousMax = 0, newMax;
        for(int money : houses){
            newMax = max(currentMax, previousMax + money);
            previousMax = currentMax;
            currentMax = newMax;
        }

        return currentMax;
    }
};