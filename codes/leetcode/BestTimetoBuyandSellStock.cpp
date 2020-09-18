class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice=INT_MAX, maxProfit=-1;
        for(int price : prices){
            if(price < buyPrice) buyPrice = price;
            else maxProfit = max(maxProfit, price - buyPrice);
        }
        return (maxProfit==-1) ? 0 : maxProfit;
    }
};