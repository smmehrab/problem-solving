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
    int findMaxForm(vector<string>& strs, int m, int n) {        
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        int ones, zeros;
        for (string str : strs) {
            ones = count(str.begin(), str.end(), '1');
            zeros = count(str.begin(), str.end(), '0');
            for (int i=n; i>=ones; i--) {
                for (int j=m; j>=zeros; j--)
                    dp[i][j] = max(dp[i][j], 1+dp[i-ones][j-zeros]);   
            }
        }
        return dp[n][m];
    }
};