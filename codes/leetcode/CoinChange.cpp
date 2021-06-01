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
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1) 
            return (amount%coins[0]==0) ? amount/coins[0] : -1;
        
        vector<int> dp;
        for(int i=0; i<=amount; i++) dp.push_back(100100);

        dp[0] = 0;
        for(int sum=1; sum<=amount; sum++) {
            for(int coin : coins) {
                if(sum>=coin)
                    dp[sum] = min(dp[sum], dp[sum-coin]+1);
            }
        }       
        
        return (dp[amount]==100100) ? -1 : dp[amount];
    }
};