class Solution {
private:
    bool dp[100100];
    bool solve(int remain) {
        if(dp[remain]) return dp[remain];
        for (int i=1; (i*i)<=remain; i++) 
            if (!solve(remain - (i*i))) 
                return dp[remain] = true;
        return dp[remain];
    }
    
public:
    bool winnerSquareGame(int n) {
        for(int i=0; i<n+10; i++) dp[i] = false;
        return solve(n);
    }
};