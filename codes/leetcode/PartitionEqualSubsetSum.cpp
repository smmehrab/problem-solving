class Solution {
public:
    bool canPartition(vector<int>& numbers) {
        int totalSum = 0;
        for(int number : numbers) totalSum+=number;

        if (totalSum%2 != 0) return false;
        
        int subsetSum = totalSum/2;
        int n = numbers.size();
        bool dp[subsetSum+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int current : numbers) {
            for (int j=subsetSum; j>=current; j--) 
                dp[j] |= dp[j - current];
        }
        return dp[subsetSum];
    }
};