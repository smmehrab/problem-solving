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
    int maxCoins(vector<int>& numbers) {
        vector<int> a(numbers.size() + 2, 1);
        for (int i = 0; i < numbers.size(); i ++) a[i+1] = numbers[i];
        int n = a.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; len ++){
            for (int l = 0; l < n - len; l ++){
                int r = l + len, tmp = INT_MIN;
                for (int k = l + 1; k < r; k ++)
                    tmp = max(tmp, a[l] * a[k] * a[r] + dp[l][k] + dp[k][r]);
                dp[l][r] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};