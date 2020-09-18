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