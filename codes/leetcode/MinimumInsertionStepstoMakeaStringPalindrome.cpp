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
private:
    int dp[501][501];
    int solve(int start, int end, string& s) {
        if (start>=end) return 0;
        if (dp[start][end]!=-1) return dp[start][end];

        dp[start][end] = (s[start]==s[end]) ? solve(start+1, end-1, s) : 1+min(solve(start+1, end, s), solve(start, end-1, s));
        return dp[start][end];
    }
    
public:
    int minInsertions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
		return solve(0, n-1, s);
    }
};