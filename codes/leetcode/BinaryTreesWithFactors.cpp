class Solution {
private:
    const int MOD = 1000000007;
    
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long int totalPossibilities = 0;
        vector<long long int> dp(n, 1);
        
        map<int, int> indexOf;
        for(int i=0; i<n; i++) 
            indexOf.insert({nums[i], i});
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0) { 
                    int leftChild = nums[j];
                    int rightChild = nums[i] / nums[j];
                    if (indexOf.find(rightChild)!=indexOf.end()) 
                        dp[i] = (dp[i] + (dp[indexOf[leftChild]] * dp[indexOf[rightChild]])) % MOD;
                }
            }
        }
        
        for(long long int possibility : dp) 
            totalPossibilities += possibility;
        return (int) (totalPossibilities % MOD);
    }
};