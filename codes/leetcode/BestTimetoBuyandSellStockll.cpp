class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buyPrice = INT_MAX, sellPrice = INT_MIN, profit = 0, maxProfit = 0;
        for(int price : prices) {
            if(price<buyPrice || price<sellPrice) { 
                maxProfit += profit;
                buyPrice = price;
                sellPrice = price;
            }
            else sellPrice = price;
            profit = sellPrice-buyPrice;
        }
        maxProfit += profit;
        return maxProfit;
    }
};