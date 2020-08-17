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