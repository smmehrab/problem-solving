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