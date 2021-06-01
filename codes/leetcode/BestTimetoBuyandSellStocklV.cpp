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
    int maxProfit(int numberOfTransactions, vector<int>& prices) {
        int numberOfDays = prices.size();
        if(numberOfDays==0 || numberOfTransactions==0) return 0;
        
        if(numberOfTransactions>=numberOfDays/2){
            long maxProfit=0;
            for(int day=1; day<numberOfDays; day++)
                if(prices[day]>prices[day-1])
                    maxProfit += prices[day]-prices[day-1];
            return maxProfit;
        }

        int dp[numberOfTransactions+1][numberOfDays+1];
        memset(dp, 0, sizeof(dp));
        for(int transaction=1; transaction<=numberOfTransactions; transaction++) {
            int maxProfit = dp[transaction][0]-prices[0];
            for(int day=1; day<=numberOfDays; day++) {
                dp[transaction][day] = max(dp[transaction][day-1], prices[day-1]+maxProfit);
                maxProfit = max(maxProfit, dp[transaction-1][day]-prices[day-1]);
            }
        }

        return dp[numberOfTransactions][numberOfDays];
    }
};