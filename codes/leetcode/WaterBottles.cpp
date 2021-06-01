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
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int emptyBottles = numBottles;
    
        while(emptyBottles/numExchange>0){
            numBottles = (emptyBottles/numExchange);
            emptyBottles %= numExchange;
            emptyBottles+=numBottles;
            result+= numBottles;
        }
    
        return result;
    }
};