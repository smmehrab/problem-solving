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
    int maxProfit(vector<int>& prices, int fee) {
        int profit=-1, investment;
        for(int price : prices) {
            if(profit == -1) {
                investment = price;
                profit = 0;            
            }   
            else {
                profit = max(profit, price-investment-fee);
                investment = min(investment, price-profit);
            }
        }
        return profit;
    }
};